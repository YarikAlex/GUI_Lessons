#ifndef FINDSYMBOL_H
#define FINDSYMBOL_H
#include <QString>
#include <QDebug>
#include <vector>
#include <utility>

class FindSymbol
{
public:
    FindSymbol();
    QString findSymbol(QString&);

private:
    qsizetype position = 0;
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
};

#endif // FINDSYMBOL_H
