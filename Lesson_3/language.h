#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QDialog>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>

namespace Ui {
class Language;
}

class Language : public QDialog
{
    Q_OBJECT

public:
    explicit Language(QWidget *parent = nullptr);
    ~Language();

private:
    Ui::Language *ui;
    QLabel *text;
    QPushButton *btn_accept;
    QComboBox *box_language;

private slots:
    void CloseForm();

signals:
    void ChooseLanguage(QString);
};

#endif // LANGUAGE_H
