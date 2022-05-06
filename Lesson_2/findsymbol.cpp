#include "findsymbol.h"
#include <algorithm>

FindSymbol::FindSymbol(){}

QString FindSymbol::findSymbol(QString& text)
{
    std::vector<std::pair<QString&, QString&>> symbols = {{_author, _authorUni},
                                                          {_euro, _euroUni},
                                                          {_ruble, _rubleUni},
                                                          {_ppm, _ppmUni},
                                                          {_symbolR, _symbolRUni}};
    for(const auto& iter: symbols)
    {
        text.replace(iter.first, iter.second);
    }
    return text;
}
