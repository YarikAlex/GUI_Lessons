#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "help_form.h"
#include "notebook.h"
#include "language.h"
#include "filesystembrowser.h"
#include <QTranslator>
#include <QPrinter>
#include <QPrintDialog>

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
    void on_action_open_triggered();
    void on_language();
    void on_action_new_triggered();
    void on_action_save_triggered();
    void on_action_dark_triggered();
    void on_action_light_triggered();
    void on_action_print_triggered();
    void on_symbols();
    void on_font();
    void on_left();
    void on_center();
    void on_right();
    void on_copyFormate();
    void on_pastFormate();
    void on_time();

public slots:
    void ChangeLanguage(QString);

private:
    Ui::MainWindow *ui;
    HelpForm *help;
    Language *languageForm;
    Notebook note;
    QTranslator translator;
    FileSystemBrowser browser;
    bool darkStyle;
    const QString darkStyleMainWindow = "QMainWindow {background-color: black}"
                                        "QMenuBar {color: grey; background-color: black}"
                                        "QMenuBar::item:selected {background: grey; color: black}"
                                        "QPushButton {color: grey; background-color: black}"
                                        "QTextEdit {color: grey; background-color: black}"
                                        "QMenu {background-color: grey; border: 0.5px solid black}"
                                        "QTreeView {color: grey; background-color: black}";
    const QString darkStyleHelpForm =   "QLabel {color: grey}"
                                        "QDialog {background-color: black}";
    const QString darkStyleLanguage =   "QDialog {background-color: black}"
                                        "QLabel {color: grey}"
                                        "QComboBox {background-color: black; color: grey; border: 0.5px solid grey; border-radius: 3px;}";
    const QString lightStyleMainWindow = "QMainWindow {background-color: #f5f5f5}"
                                         "QMenuBar {color: black; background-color: #f5f5f5}"
                                         "QMenuBar::item:selected {background: #add8e6; color: black}"
                                         "QPushButton {color: black; background-color: #f5f5f5;}"
                                         "QTextEdit {color: black; background-color: white}"
                                         "QMenu {background-color: #f5f5f5; color: black; border: none}"
                                         "QMenu::item::selected {background: #add8e6; color: black}";
    void SwitchLanguage(QString language);
    void SetFontToolBar();
    void SetFileToolBar();
    void SetEditToolBar();

};
#endif // MAINWINDOW_H
