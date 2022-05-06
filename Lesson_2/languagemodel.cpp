#include "languagemodel.h"
#include <QIcon>
#include <QApplication>
#include <QStyle>

LanguageModel::LanguageModel(QObject *parent) : QStandardItemModel(parent)
{
    for(int iter = 0; iter<_languages.size(); ++iter)
    {
        this->appendRow(new QStandardItem(QIcon(":/img/" + _icons.at(iter)), _languages.at(iter)));
    }
}

Qt::ItemFlags LanguageModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEnabled | QStandardItemModel::flags(index);
}

void LanguageModel::addNewLanguage(const QString &newLanguage)
{
    this->appendRow(new QStandardItem(QIcon(":/img/new.png"), newLanguage));
}
