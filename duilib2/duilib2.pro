#-------------------------------------------------
#
# Project created by QtCreator 2016-08-13T21:20:03
#
#-------------------------------------------------

QT       += widgets

TARGET = duilib2
TEMPLATE = lib

DEFINES += DUILIB2_LIBRARY

SOURCES += \
    src/System.cpp \
    src/PushButton.cpp \
    src/Window.cpp \
    src/WindowManager.cpp \
    src/ResourceManager.cpp

HEADERS +=\
        duilib2_global.h \
    include/System.h \
    include/Singleton.h \
    include/duilib2.h \
    include/PushButton.h \
    include/Window.h \
    include/WindowManager.h \
    include/ResourceManager.h

INCLUDEPATH += include

unix {
    target.path = /usr/lib
    INSTALLS += target
}
