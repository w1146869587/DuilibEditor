#-------------------------------------------------
#
# Project created by QtCreator 2016-08-13T21:20:03
#
#-------------------------------------------------

QT       += widgets xml

TARGET = duilib2
TEMPLATE = lib

DEFINES += DUILIB2_LIBRARY

SOURCES += \
    src/System.cpp \
    src/PushButton.cpp \
    src/Window.cpp \
    src/WindowManager.cpp \
    src/ResourceManager.cpp \
    src/RawDataContainer.cpp \
    src/XmlHandler.cpp \
    src/XmlParsers/QtXmlParser.cpp \
    src/Qt/SystemImpl.cpp \
    src/XmlAttributes.cpp \
    src/ArchiveManager.cpp \
    src/FileSystemArchive.cpp \
    src/QtResArchive.cpp \
    src/ZipArchive.cpp \
    src/Exception.cpp \
    src/LayoutXmlHandler.cpp

HEADERS +=\
    include/System.h \
    include/Singleton.h \
    include/duilib2.h \
    include/PushButton.h \
    include/Window.h \
    include/WindowManager.h \
    include/ResourceManager.h \
    include/Qt/duilib2_global.h \
    include/XmlParsers/QtXmlParser.h \
    include/XmlHandler.h \
    include/XmlParser.h \
    include/RawDataContainer.h \
    include/XmlAttributes.h \
    include/Archive.h \
    include/ArchiveFactory.h \
    include/ArchiveManager.h \
    include/FileSystemArchive.h \
    include/QtResArchive.h \
    include/ZipArchive.h \
    include/Exception.h \
    include/LayoutXmlHandler.h

INCLUDEPATH += \
    include \
    include/Qt \
    boost_1_60_0

unix {
    target.path = /usr/lib
    INSTALLS += target
}
