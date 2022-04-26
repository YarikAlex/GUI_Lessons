#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "findsymbol.h"
#include "languagemodel.h"

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
    void on_pushButton_clicked();
    void on_IconMode_checkBox_clicked(bool checked);
    void on_btn_addLanguage_clicked();
    void on_btn_removeLanguage_clicked();

private:
    Ui::MainWindow *ui;
    FindSymbol sym;
    LanguageModel *myModel;
};
#endif // MAINWINDOW_H
