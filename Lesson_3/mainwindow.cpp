#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    if(help==nullptr)
        help = new HelpForm(this);
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

void MainWindow::SwitchLanguage(const QString& language)
{
    if(translator.load(":/languges/switchlang_" + language + ".qm"))
        qApp->installTranslator(&translator);
}

void MainWindow::on_btn_language_clicked()
{
    languageForm = new Language(this);
    languageForm->show();
    connect(languageForm, SIGNAL(ChooseLanguage(QString)), this,SLOT(ChangeLanguage(QString)));
}

void MainWindow::ChangeLanguage(const QString& language)
{
    SwitchLanguage(language);
}

void MainWindow::on_action_new_triggered()
{
    MainWindow *newWindow = new MainWindow(this);
    newWindow->show();
}
