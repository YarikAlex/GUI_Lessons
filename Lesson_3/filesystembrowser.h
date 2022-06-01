#ifndef FILESYSTEMBROWSER_H
#define FILESYSTEMBROWSER_H

#include <QWidget>
#include <QStandardItemModel>
#include "searcher.h"
#include <memory>

class FileSystemBrowser : public QWidget
{
    Q_OBJECT
public:
    explicit FileSystemBrowser(QWidget *parent = nullptr);
    ~FileSystemBrowser();
    QStandardItemModel* getCurrentModel()const{return model;}
    void FindFile(const QString& fileName);
public slots:
    void getResult(QString& result);
private:
    QStandardItemModel* model;
    QString currentPath;
    Searcher *_searcher;
};

#endif // FILESYSTEMBROWSER_H
