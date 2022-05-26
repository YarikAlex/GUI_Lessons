#ifndef HELP_FORM_H
#define HELP_FORM_H

#include <QDialog>

namespace Ui {
class HelpForm;
}

class HelpForm : public QDialog
{
    Q_OBJECT

public:
    explicit HelpForm(QWidget *parent = nullptr);
    ~HelpForm();

private slots:
    void on_btn_Ok_clicked();

private:
    Ui::HelpForm *ui;

    QString loadText(const QString &dir);
};

#endif // HELP_FORM_H
