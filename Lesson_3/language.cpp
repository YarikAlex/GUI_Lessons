#include "language.h"
#include "ui_language.h"

Language::Language(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Language)
{
    ui->setupUi(this);
    this->resize(200, 200);
    text = new QLabel(this);
    text->setText(tr("Выберите язык"));
    text->resize(150, 20);
    text->move(50,50);
    box_language = new QComboBox(this);
    box_language->addItem(tr("Русский"));
    box_language->addItem(tr("Английский"));
    box_language->addItem(tr("Французский"));
    box_language->move(50, 80);
    btn_accept = new QPushButton(this);
    btn_accept->setText(tr("Принять"));
    btn_accept->move(100, 150);
    connect(btn_accept, SIGNAL(clicked()), this, SLOT(CloseForm()));
}

Language::~Language()
{
    delete ui;
}

void Language::CloseForm()
{
    if(box_language->currentIndex()==0)
        emit ChooseLanguage("ru");
    if(box_language->currentIndex()==1)
        emit ChooseLanguage("en");
    if(box_language->currentIndex()==2)
        emit ChooseLanguage("fr");

    this->close();
}
