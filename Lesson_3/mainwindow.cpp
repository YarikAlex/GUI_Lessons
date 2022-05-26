#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    if(help == nullptr)
        help = new HelpForm(this);
    if(darkStyle)
        help->setStyleSheet(loadTheme(darkThemePath));
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

//buttons
void MainWindow::on_btn_help_clicked()
{
    QString text = ui->textEdit->toPlainText();
    ui->textEdit->setText(note.setUnicodeSymbols(text));
}

void MainWindow::on_btn_open_clicked()
{
    this->on_action_open_triggered();
}

void MainWindow::on_btn_save_clicked()
{
    this->on_action_save_triggered();
}

void MainWindow::SwitchLanguage(QString language)
{
    if(translator.load(":/languges/switchlang_" + language + ".qm"))
        qApp->installTranslator(&translator);
}

QString MainWindow::loadTheme(const QString &dir)
{
    QFile file (dir);
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        return stream.read(file.size());
    }
    return QString {};
}

void MainWindow::on_btn_language_clicked()
{
    languageForm = new Language(this);
    if (darkStyle)
        languageForm->setStyleSheet(loadTheme(darkThemePath));
    languageForm->show();
    connect(languageForm, SIGNAL(ChooseLanguage(QString)), this,SLOT(ChangeLanguage(QString)));
}

void MainWindow::ChangeLanguage(const QString &language)
{
    SwitchLanguage(language);
}

void MainWindow::on_action_new_triggered()
{
    MainWindow *newWindow = new MainWindow(this);
    newWindow->show();
}

void MainWindow::on_action_dark_triggered()
{
    this->setStyleSheet(loadTheme(darkThemePath));
    darkStyle = true;
}

void MainWindow::on_action_light_triggered()
{
    this->setStyleSheet(loadTheme(lightThemePath));
    darkStyle = false;
}
