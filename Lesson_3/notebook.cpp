#include "notebook.h"
#include <QStringDecoder>
#include <QTextStream>
#include <QDebug>


Notebook::Notebook(QWidget *parent) : QWidget(parent)
{

}

QString Notebook::openFile(QString oldText)
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Открыть файл"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), _filter);
    if(filename.length()>0)
    {
        int textIndex = filename.indexOf(".txt");
        if(textIndex != -1 && filename.length() - 4 == textIndex)
        {
            QFile file(filename);
            if(file.open(QFile::ReadOnly | QFile::ExistingOnly))
            {
                QTextStream stream(&file);
                auto toUtf16 = QStringDecoder(QStringDecoder::Utf8);
                return toUtf16(stream.readAll().toUtf8());
            }
            else
            {
                qDebug() << "Error: " << file.errorString();
            }
        }
        return oldText;// it would be better to show the user the message "Invalid file extension"
    }
    return oldText;
}

void Notebook::saveFile(QString text)
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Сохранить файл"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), _filter);
    if(filename.length() > 0)
    {

        int textIndex = filename.indexOf(".txt");
        if(textIndex != -1 && filename.length() - 4 == textIndex)
        {
            QFile file(filename);
            if(file.open(QFile::WriteOnly))
            {
                QTextStream stream(&file);
                stream << text.toUtf8();
            }
        }
    }
}

QString Notebook::setUnicodeSymbols(QString text)
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

QString Notebook::changeSymbol(QString string, QString symbol, uint symbolUni)
{
    qsizetype indexpos = string.indexOf(symbol, position);
        string.remove(indexpos, symbol.size());
        string.insert(indexpos, QChar::fromUcs4(symbolUni));

        return string;
}
