#ifndef NOTEBOOK_H
#define NOTEBOOK_H
#include <QWidget>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QStandardPaths>

class Notebook : public QWidget
{
public:
    Notebook(QWidget *parent = nullptr);
    QString openFile(QString);
    void saveFile(QString);
    QString setUnicodeSymbols(QString);
private:
    QString changeSymbol(QString, QString, uint);

    QString _filter = "text files (*.txt);; All(*.*)";
    qsizetype position;
    QString _author = "(c)";
    QString _euro = "@EURO@";
    QString _ruble = "@RUB@";
    QString _ppm = "@ppm@";
    QString _symbolR = "(R)";
    uint _authorUni = 0x00A9;
    uint _euroUni = 0x20AC;
    uint _rubleUni = 0x20BD;
    uint _ppmUni = 0x2030;
    uint _symbolRUni = 0x00AE;
};

#endif // NOTEBOOK_H
