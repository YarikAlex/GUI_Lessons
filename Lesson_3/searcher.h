#ifndef SEARCHER_H
#define SEARCHER_H

#include <QThread>
#include <QObject>
#include <QFileInfoList>

class Searcher : public QThread
{
    Q_OBJECT
public:
    Searcher(const QString &dir, const QString &file);
protected:
    void run() override;
private:
    QString _dir;
    QString _fileName;
    void findFile(QFileInfoList &list);
signals:
    void resultReady(QString& result);
};

#endif // SEARCHER_H
