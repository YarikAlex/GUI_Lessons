#pragma once

#include <QObject>
#include <QStandardItemModel>
#include <QStandardItem>

class LanguageModel : public QStandardItemModel
{
    Q_OBJECT
public:
    LanguageModel(QObject *parent = nullptr);
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    void addNewLanguage(const QString&);

private:
    QStringList _languages = {"C++", "Java", "C#", "PHP", "Python", "JavaSript"};
    QStringList _icons = {"c++.png", "java.png", "c#.png", "php.png", "python.png", "javascript.png"};
};

