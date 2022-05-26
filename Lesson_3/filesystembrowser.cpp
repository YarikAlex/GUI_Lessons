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
    if(!disks.isEmpty())
        currentPath = disks.at(0).path();
    items.append(new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_DriveHDIcon)), currentPath));
    model->appendRow(items);

    //set directories
    QDir dir(currentPath);
    dir.setFilter(QDir::NoFilter | QDir::NoSymLinks | QDir::Dirs);
    QFileInfoList foldersList = dir.entryInfoList();
    QList<QStandardItem*> folders;
    for(auto iter: foldersList)
    {
        folders.append(new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_DirIcon)), iter.baseName()));
    }
    items.at(0)->appendRows(folders);

    //set files
    for(int iter = 0; iter < foldersList.count(); ++iter)
    {
        QString newCurrentPath(foldersList.at(iter).filePath());
        dir.setPath(newCurrentPath);
        dir.setFilter(QDir::NoSymLinks|QDir::NoDotAndDotDot | QDir::Files|QDir::Dirs);
        QFileInfoList filesList = dir.entryInfoList();
        QList<QStandardItem*> files;
        for(auto &iter: filesList)
        {
            if(iter.isFile())
                files.append(new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_FileIcon)), iter.baseName()));
            if(iter.isDir())
                files.append(new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_DirIcon)), iter.baseName()));
        }
        folders.at(iter)->appendRows(files);
    }
}

FileSystemBrowser::~FileSystemBrowser()
{
    delete model;
}
