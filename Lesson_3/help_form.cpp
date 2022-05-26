#include "help_form.h"
#include "ui_help_form.h"
#include <QFile>
#include <QTextStream>

HelpForm::HelpForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpForm)
{
    ui->setupUi(this);
    ui->label_text->setText(loadText(":/res/help.txt"));
}

HelpForm::~HelpForm()
{
    delete ui;
}

QString HelpForm::loadText(const QString &dir)
{
    QFile file (dir);
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        return stream.read(file.size());
    }
    return QString {};
}

void HelpForm::on_btn_Ok_clicked() { this->close(); }
