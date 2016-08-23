#-------------------------------------------------
#
# Project created by QtCreator 2016-08-13T21:52:41
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

INCLUDEPATH += $$PWD/../duilib2/include \
            $$PWD/../duilib2/include/Qt \
            $$PWD/../duilib2/boost_1_60_0

INCLUDEPATH += $$PWD/../duilib2
DEPENDPATH += $$PWD/../duilib2

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../duilib2/release/ -lduilib2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../duilib2/debug/ -lduilib2
else:unix: LIBS += -L$$OUT_PWD/../duilib2/ -lduilib2

