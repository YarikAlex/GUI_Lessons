#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "help_form.h"
#include "notebook.h"
#include "language.h"
#include <QTranslator>


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
    void on_action_exit_triggered();
    void on_action_help_triggered();
    void on_btn_help_clicked();
    void on_action_open_triggered();
    void on_btn_open_clicked();
    void on_btn_save_clicked();
    void on_btn_language_clicked();

    void on_action_new_triggered();

    void on_action_save_triggered();

public slots:
    void ChangeLanguage(QString);

private:
    Ui::MainWindow *ui;
    HelpForm *help;
    Language *languageForm;
    Notebook note;
    QTranslator translator;


    void SwitchLanguage(QString language);

};
#endif // MAINWINDOW_H
