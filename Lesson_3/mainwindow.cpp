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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QToolBar *fileTool = new QToolBar(tr("File"), this);
    QToolBar *editTool = new QToolBar(tr("Edit"), this);

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

    QAction *symbols = new QAction(tr("Symbols"), this);
    connect(symbols, &QAction::triggered, this, &MainWindow::on_symbols);
    editTool->addAction(symbols);

    QAction *language = new QAction(tr("Language"), this);
    connect(language, &QAction::triggered, this, &MainWindow::on_language);
    editTool->addAction(language);

    this->addToolBar(fileTool);
    this->addToolBar(editTool);

    ui->treeView->setModel(browser.getCurrentModel());
    SwitchLanguage(QLocale::system().name());
    darkStyle = false;
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

//methods
void MainWindow::SwitchLanguage(QString language)
{
    translator.load(":/languges/switchlang_" + language);
    qApp->installTranslator(&translator);
}

void MainWindow::ChangeLanguage(QString language)
{
    SwitchLanguage(language);
}
