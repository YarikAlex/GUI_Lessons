#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtMath"
#include "QDebug"

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


void MainWindow::on_btn_solve_clicked()
{
    a = ui->l_a->text().toDouble();
    b = ui->l_b->text().toDouble();
    c = ui->l_c->text().toDouble();

    if(a != 0) ui->l_answer->setText(SolveQuadraticEquation());
    else ui->l_answer->setText(SolveLinearEquation());
}

QString MainWindow::SolveQuadraticEquation()
{
    QString answer;
    double discr = qPow(b, 2) - 4 * a * c;
    if (discr < 0) answer = "Нет корней";
    if (discr == 0) answer = "X = " + answer.setNum((-b/(2*a)));
    if (discr > 0)
    {
        QString x1, x2;
        x1.setNum((-b + qSqrt(discr)) / (2 * a));
        x2.setNum((-b - qSqrt(discr)) / (2 * a));
        answer = "X1 = " + x1 + ", X2 = " + x2;
    }
    return answer;
}

QString MainWindow::SolveLinearEquation()
{
    QString answer;
    return "X = " + answer.setNum(-c/b);
}

void MainWindow::on_btn_findC_clicked()
{
    a = ui->l_sideA->text().toDouble();
    b = ui->l_sideB->text().toDouble();
    ui->l_sideC->setText(SolveTriangleSide());
}


QString MainWindow::SolveTriangleSide()
{
    QString answer;
    return answer.setNum((qSqrt(qPow(a, 2) + qPow(b, 2) - (2*a*b*qCos(corner)))), 'g', 2);
}

void MainWindow::on_degreesRradioButton_clicked(bool checked)
{
    if(checked)
    {
        corner = qDegreesToRadians(ui->l_corner->text().toDouble());
    }
}



void MainWindow::on_changeTextBtn_clicked()
{
    ui->secondTextEdit->setPlainText(ui->firstTextEdit->toPlainText());
}


void MainWindow::on_fromSecondtoFirstBtn_clicked()
{
    ui->firstTextEdit->setPlainText(ui->secondTextEdit->toPlainText());
}


void MainWindow::on_setHtmlBtn_clicked()
{
    QTextDocument *text = new QTextDocument;
    text->setHtml("<font color='red'>Text from html code</font>");
    ui->secondTextEdit->setPlainText(text->toPlainText());
}
