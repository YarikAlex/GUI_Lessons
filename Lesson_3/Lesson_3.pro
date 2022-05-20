QT       += core gui printsupport
TRANSLATIONS += switchlang_ru.ts switchlang_en.ts switchlang_fr.ts
CODECFORSRC = UTF-8

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NoteBook
TEMPLATE = app
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    filesystembrowser.cpp \
    help_form.cpp \
    language.cpp \
    main.cpp \
    mainwindow.cpp \
    notebook.cpp

HEADERS += \
    filesystembrowser.h \
    help_form.h \
    language.h \
    mainwindow.h \
    notebook.h

FORMS += \
    help_form.ui \
    language.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
