#ifndef NOTEBOOK_H
#define NOTEBOOK_H
#include <QWidget>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QStandardPaths>
#include <QFont>
#include <QTextCharFormat>
#include <QFontDialog>

class Notebook : public QWidget
{
public:
    Notebook(QWidget *parent = nullptr);
    QString openFile(QString);
    void saveFile(QString);
    QString setUnicodeSymbols(QString&);
    QTextCharFormat changeFontFormat(QFont &);
    void getTextFormatting(QTextCharFormat &);
    QTextCharFormat setTextFormatting(){return _buffer;}
private:
    QString _filter = "text files (*.txt);; All(*.*)";
    qsizetype position;
    QString _author = "(c)";
    QString _euro = "@EURO@";
    QString _ruble = "@RUB@";
    QString _ppm = "@ppm@";
    QString _symbolR = "(R)";
    QString _authorUni = QChar(0x00A9);
    QString _euroUni = QChar(0x20AC);
    QString _rubleUni = QChar(0x20BD);
    QString _ppmUni = QChar(0x2030);
    QString _symbolRUni = QChar(0x00AE);
    QTextCharFormat _buffer;
};

#endif // NOTEBOOK_H
