#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextDocument>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_solve_clicked();
    void on_btn_findC_clicked();
    void on_degreesRradioButton_clicked(bool checked);
    void on_changeTextBtn_clicked();
    void on_fromSecondtoFirstBtn_clicked();
    void on_setHtmlBtn_clicked();

private:
    Ui::MainWindow *ui;
    double a, b, c, corner;


    QString SolveQuadraticEquation();
    QString SolveLinearEquation();
    QString SolveTriangleSide();
};
#endif // MAINWINDOW_H
