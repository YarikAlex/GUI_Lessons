#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QPalette>
#include <QPainter>
#include <QMenu>
#include <QToolBar>
#include <QIcon>
#include <QMessageBox>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SetFileToolBar();
    SetEditToolBar();
    SetFontToolBar();
    ui->treeView->setModel(browser.getCurrentModel());
    darkStyle = false;
    //ui->lineSearch->setText(browser.getCount());
}

MainWindow::~MainWindow()
{
    delete ui;
}

//actions
void MainWindow::on_action_exit_triggered()
{
    this->close();
}

void MainWindow::on_action_help_triggered()
{
    help = new HelpForm(this);
    if(darkStyle)
        help->setStyleSheet(darkStyleHelpForm);
    help->show(); 
}

void MainWindow::on_action_open_triggered()
{
    ui->textEdit->setText(note.openFile(ui->textEdit->toPlainText()));
}

void MainWindow::on_action_save_triggered()
{
    note.saveFile(ui->textEdit->toPlainText());
}

void MainWindow::on_action_new_triggered()
{
    MainWindow *newWindow = new MainWindow(this);
    newWindow->show();
}

void MainWindow::on_language()
{
    languageForm = new Language(this);
    if (darkStyle)
        languageForm->setStyleSheet(darkStyleLanguage);
    languageForm->show();
    connect(languageForm, SIGNAL(ChooseLanguage(QString)), this,SLOT(ChangeLanguage(QString)));
}

void MainWindow::on_action_dark_triggered()
{
    this->setStyleSheet(darkStyleMainWindow);
    darkStyle = true;
}

void MainWindow::on_action_light_triggered()
{
    this->setStyleSheet(lightStyleMainWindow);
    darkStyle = false;
}

void MainWindow::on_action_print_triggered()
{
    QPrinter printer;
    QPrintDialog dlg(&printer, this);
    dlg.setWindowTitle(tr("Print"));
    if(dlg.exec() != QDialog::Accepted)
        return;
    ui->textEdit->print(&printer);
}

void MainWindow::on_symbols()
{
    QString text = ui->textEdit->toPlainText();
    ui->textEdit->setText(note.setUnicodeSymbols(text));
}

void MainWindow::on_font()
{
    QFont font = ui->textEdit->textCursor().charFormat().font();
    ui->textEdit->textCursor().setCharFormat(note.changeFontFormat(font));
}

void MainWindow::on_left()
{
    ui->textEdit->setAlignment(Qt::AlignLeft);
}

void MainWindow::on_center()
{
    ui->textEdit->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_right()
{
    ui->textEdit->setAlignment(Qt::AlignRight);
}

void MainWindow::on_copyFormate()
{
    QTextCharFormat format = ui->textEdit->textCursor().charFormat();
    note.getTextFormatting(format);
}

void MainWindow::on_pastFormate()
{
    ui->textEdit->textCursor().setCharFormat(note.setTextFormatting());
}

void MainWindow::on_time()
{
    QDateTime dateTime {QDateTime::currentDateTime()};
    ui->textEdit->textCursor().insertText(dateTime.toString("dd.MM.yyyy h:m:ss ap"));
}

//methods
void MainWindow::SwitchLanguage(QString language)
{
    QString pathLanguage = ":/languges/switchlang_" + language + ".qm";
    if(translator.load(pathLanguage))
        qApp->installTranslator(&translator);
}

void MainWindow::SetFontToolBar()
{
    QToolBar *fontTool = new QToolBar(tr("Font"), this);
    QAction *font = new QAction(tr("Font"), this);
    connect(font, &QAction::triggered, this, &MainWindow::on_font);
    fontTool->addAction(font);
    fontTool->addSeparator();

    const QIcon alignLeft = QIcon::fromTheme("textFormat", QIcon(":/images/alignLeft.png"));
    QAction *leftText = new QAction (alignLeft, tr("Align left"), this);
    connect(leftText, &QAction::triggered, this, &MainWindow::on_left);
    fontTool->addAction(leftText);

    const QIcon alignCenter = QIcon::fromTheme("textFormat", QIcon(":/images/alignCenter.png"));
    QAction *centerText = new QAction (alignCenter, tr("Align center"), this);
    connect(centerText, &QAction::triggered, this, &MainWindow::on_center);
    fontTool->addAction(centerText);

    const QIcon alignRight = QIcon::fromTheme("textFormat", QIcon(":/images/alignRight.png"));
    QAction *rightText = new QAction (alignRight, tr("Align right"), this);
    connect(rightText, &QAction::triggered, this, &MainWindow::on_right);
    fontTool->addAction(rightText);
    fontTool->addSeparator();

    QAction *copyFormat = new QAction(tr("CopyFormat"), this);
    connect(copyFormat, &QAction::triggered, this, &MainWindow::on_copyFormate);
    fontTool->addAction(copyFormat);

    QAction *pasteFormat = new QAction(tr("PasteFormat"), this);
    connect(pasteFormat, &QAction::triggered, this, &MainWindow::on_pastFormate);
    fontTool->addAction(pasteFormat);

    this->addToolBar(fontTool);
}

void MainWindow::SetFileToolBar()
{
    QToolBar *fileTool = new QToolBar(tr("File"), this);

    const QIcon newIcon = QIcon::fromTheme("fileTheme", QIcon(":/images/newIcon.png"));
    QAction *newFile = new QAction(newIcon, tr("New"), this);
    connect(newFile, &QAction::triggered, this, &MainWindow::on_action_new_triggered);
    fileTool->addAction(newFile);

    const QIcon openIcon = QIcon::fromTheme("fileTheme", QIcon(":/images/openIcon.png"));
    QAction *openFile = new QAction(openIcon, tr("Open"), this);
    connect(openFile, &QAction::triggered, this, &MainWindow::on_action_open_triggered);
    fileTool->addAction(openFile);

    const QIcon saveIcon = QIcon::fromTheme("fileTheme", QIcon(":/images/saveIcon.png"));
    QAction *saveFile = new QAction(saveIcon, tr("Save"), this);
    connect(saveFile, &QAction::triggered, this, &MainWindow::on_action_save_triggered);
    fileTool->addAction(saveFile);
    this->addToolBar(fileTool);
}

void MainWindow::SetEditToolBar()
{
    QToolBar *editTool = new QToolBar(tr("Edit"), this);

    QAction *symbols = new QAction(tr("Symbols"), this);
    connect(symbols, &QAction::triggered, this, &MainWindow::on_symbols);
    editTool->addAction(symbols);

    QAction *language = new QAction(tr("Language"), this);
    connect(language, &QAction::triggered, this, &MainWindow::on_language);
    editTool->addAction(language);

    const QIcon timeIcon = QIcon::fromTheme("editTheme", QIcon(":/images/clockIcon.png"));
    QAction *time = new QAction(timeIcon, tr("Time"), this);
    connect(time, &QAction::triggered, this, &MainWindow::on_time);
    editTool->addAction(time);

    this->addToolBar(editTool);
}

void MainWindow::ChangeLanguage(QString language)
{
    SwitchLanguage(language);
}

void MainWindow::on_btn_Find_clicked()
{
    QString text = ui->lineSearch->text();
    browser.FindFile(text);
}

