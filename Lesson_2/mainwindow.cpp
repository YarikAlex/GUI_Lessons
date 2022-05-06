#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myModel = new LanguageModel(this);
    ui->listView->setModel(myModel);
    ui->listView->setMovement(QListView::Free);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString text = ui->plainTextEdit->toPlainText();
    ui->plainTextEdit->setPlainText(sym.findSymbol(text));
}

void MainWindow::on_IconMode_checkBox_clicked(bool checked)
{
    if(checked)
    {
        ui->listView->setViewMode(QListView::IconMode);
    }
    else
        ui->listView->setViewMode(QListView::ListMode);
}

void MainWindow::on_btn_addLanguage_clicked()
{
    myModel->addNewLanguage(ui->line_newLanguage->text());
}

void MainWindow::on_btn_removeLanguage_clicked()
{
    myModel->removeRows(ui->listView->currentIndex().row(), 1);
}
