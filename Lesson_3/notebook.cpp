#include "notebook.h"
#include <QStringDecoder>
#include <QTextStream>
#include <QDebug>
#include <vector>
#include <utility>

Notebook::Notebook(QWidget *parent) : QWidget(parent)
{
    position = 0;
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

QString Notebook::setUnicodeSymbols(QString& text)
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
