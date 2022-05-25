#include "language.h"
#include "ui_language.h"

Language::Language(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Language)
{
    ui->setupUi(this);
    this->resize(150, 150);
    text = new QLabel(this);
    text->setText(tr("Выберите язык"));
    text->setGeometry(30, 20, 100, 25);

    box_language = new QComboBox(this);
    box_language->setGeometry(text->geometry().x(), text->geometry().y()+text->geometry().height()+5, 100, 25);
    box_language->addItem(tr("Русский"));
    box_language->addItem(tr("Английский"));
    box_language->addItem(tr("Французский"));

    btn_accept = new QPushButton(this);
    btn_accept->setText(tr("Принять"));
    btn_accept->setGeometry(box_language->geometry().x(), box_language->geometry().y()+ box_language->geometry().height()+10, 100, 25);

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
