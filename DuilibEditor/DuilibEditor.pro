#-------------------------------------------------
#
# Project created by QtCreator 2016-08-13T21:17:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DuilibEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../duilib2/release/ -lduilib2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../duilib2/debug/ -lduilib2
else:unix: LIBS += -L$$OUT_PWD/../duilib2/ -lduilib2

INCLUDEPATH += $$PWD/../duilib2
DEPENDPATH += $$PWD/../duilib2
