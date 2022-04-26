#include "findsymbol.h"
#include <algorithm>

FindSymbol::FindSymbol()
{
    position = 0;
}

QString FindSymbol::findSymbol(QString text)
{
    while(text.indexOf(_author, position) != -1)
    {
        text = changeSymbol(text, _author, _authorUni);
    }
    while(text.indexOf(_euro, position) != -1)
    {
        text = changeSymbol(text, _euro, _euroUni);
    }
    while(text.indexOf(_ruble, position) != -1)
    {
        text = changeSymbol(text, _ruble, _rubleUni);
    }
    while(text.indexOf(_ppm, position) != -1)
    {
        text = changeSymbol(text, _ppm, _ppmUni);
    }
    while(text.indexOf(_symbolR, position) != -1)
    {
        text = changeSymbol(text, _symbolR, _symbolRUni);
    }

    return text;
}

QString FindSymbol::changeSymbol(QString string, QString symbol, uint symbolUni)
{
    qsizetype indexpos = string.indexOf(symbol, position);
    string.remove(indexpos, symbol.size());
    string.insert(indexpos, QChar::fromUcs4(symbolUni));

    return string;
}
