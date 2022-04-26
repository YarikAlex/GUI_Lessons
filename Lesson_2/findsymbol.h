#ifndef FINDSYMBOL_H
#define FINDSYMBOL_H
#include <QString>
#include <QDebug>

class FindSymbol
{
public:
    FindSymbol();
    QString findSymbol(QString);
    QString changeSymbol(QString, QString, uint);

private:
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

#endif // FINDSYMBOL_H
