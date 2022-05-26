#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
           if(translator.load(QLocale(), QString("switchlang"), QString("_"), QString(":/languges"), QString(".qm")))
               QCoreApplication::installTranslator(&translator);
    MainWindow w;
    w.show();
    return a.exec();
}
