#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QPalette>
#include <QPainter>


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

void MainWindow::on_action_new_triggered()
{
    MainWindow *newWindow = new MainWindow(this);
    newWindow->show();
}

void MainWindow::on_btn_language_clicked()
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
