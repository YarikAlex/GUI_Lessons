#include "notebook.h"
#include <QStringDecoder>
#include <QTextStream>
#include <QDebug>
#include <vector>
#include <utility>

Notebook::Notebook(QWidget *parent) : QWidget(parent) {}

QString Notebook::openFile(const QString& oldText)
{
    const QString filename {QFileDialog::getOpenFileName(this, tr("Открыть файл"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), _filter)};
    if(filename.isEmpty())
        return QString{};
    else
    {
        QFile file(filename);
        if(file.open(QFile::ReadOnly | QFile::ExistingOnly))
        {
            QTextStream stream(&file);
            auto toUtf16 = QStringDecoder(QStringDecoder::Utf8);
            return toUtf16(stream.readAll().toUtf8());
        }
       return oldText;
    }
}

void Notebook::saveFile(const QString& text)
{
    const QString filename {QFileDialog::getSaveFileName(this, tr("Сохранить файл"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), _filter)};
    if(!filename.isEmpty())
    {
        const QString txtFormat {QStringLiteral(".txt")};
        if(filename.endsWith(txtFormat)&&filename.length() > txtFormat.size())
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

QString Notebook::setUnicodeSymbols(QString& text)
{
    const std::vector<std::pair<QString&, QString&>> symbols = {{_author, _authorUni},
                                                          {_euro, _euroUni},
                                                          {_ruble, _rubleUni},
                                                          {_ppm, _ppmUni},
                                                          {_symbolR, _symbolRUni}};
    for(const auto &iterSymbolPair : symbols)
    {
        text.replace(iterSymbolPair.first, iterSymbolPair.second);
    }
    return text;
}
