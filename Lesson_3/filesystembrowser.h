#ifndef FILESYSTEMBROWSER_H
#define FILESYSTEMBROWSER_H

#include <QWidget>
#include <QStandardItemModel>

class FileSystemBrowser : public QWidget
{
    Q_OBJECT
public:
    explicit FileSystemBrowser(QWidget *parent = nullptr);
    ~FileSystemBrowser();
    QStandardItemModel* getCurrentModel()const{return model;}

private:
    QStandardItemModel* model;
    QString currentPath;
};

#endif // FILESYSTEMBROWSER_H
