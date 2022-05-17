#include "filesystembrowser.h"
#include <QDir>
#include <QApplication>
#include <QStyle>

FileSystemBrowser::FileSystemBrowser(QWidget* parent) : QWidget(parent), model(nullptr)
{
    model = new QStandardItemModel(this);
    QList<QStandardItem*> items;

    //set disks
    QFileInfoList disks = QDir::drives();
    currentPath = disks.at(0).path();
    items.append(new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_DriveHDIcon)), currentPath));
    model->appendRow(items);

    //set directories
    QDir dir(currentPath);
    dir.setFilter(QDir::Hidden | QDir::NoSymLinks | QDir::Dirs);
    QStringList foldersList = dir.entryList();
    QList<QStandardItem*> folders;
    for(int iter = 0; iter < foldersList.count(); ++iter)
    {
        folders.append(new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_DirIcon)),
                                         foldersList.at(iter)));
    }
    items.at(0)->appendRows(folders);

    //set files
    dir.setFilter(QDir::Hidden | QDir::NoSymLinks | QDir::Files);
    QList<QStandardItem*> files;
    for(int iter = 0; iter < foldersList.count(); ++iter)
    {
        files.append(new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_FileIcon)),
                                         foldersList.at(iter)));
    }
    items.at(0)->appendRows(files);
}

FileSystemBrowser::~FileSystemBrowser()
{
    delete model;
}
