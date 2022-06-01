#include "searcher.h"
#include <QDir>

Searcher::Searcher(const QString& dir, const QString& file)
    : _dir(dir), _fileName(file){}

void Searcher::run()
{
    QDir search(_dir);
    search.setFilter(QDir::Hidden | QDir::Dirs | QDir::Files | QDir::NoSymLinks);
    QFileInfoList folderList = search.entryInfoList();
    findFile(folderList);

    for(int i = 0; i < folderList.count(); ++i)
    {
        if(!folderList.at(i).isDir())
            continue;
        else
        {
            QString path(folderList.at(i).filePath());
            search.setPath(path);
            QFileInfoList innerList = search.entryInfoList();
            findFile(innerList);
        }
    }
}

void Searcher::findFile(QFileInfoList& list)
{
    for(auto &iter: list)
    {
        if(iter.baseName() == _fileName)
        {
            QString result = "Path to " + iter.fileName() + " is " + iter.absoluteFilePath();
            emit resultReady(result);
        }
    }
}
