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
    src/XmlAttributes.cpp \
    src/ArchiveManager.cpp \
    src/Exception.cpp \
    src/LayoutXmlHandler.cpp \
    src/NativeWindows/QtMainWindow.cpp \
    src/NativeWindows/Win32MainWindow.cpp \
    src/MainWindow.cpp \
    src/Property.cpp \
    src/PropertySet.cpp \
    src/WindowFactory.cpp \
    src/SystemImpl/QtSystemImpl.cpp \
    src/Archives/FileSystemArchive.cpp \
    src/Archives/QtResArchive.cpp \
    src/Archives/ZipArchive.cpp \
    src/PropertyParserManager.cpp \
    src/PropertyParsers.cpp \
    src/PropertyTypes.cpp \
    src/RenderSystems/QtRenderSystem.cpp \
    src/RenderSystem.cpp

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
    include/Exception.h \
    include/LayoutXmlHandler.h \
    include/NativeWindows/QtMainWindow.h \
    include/NativeWindows/Win32MainWindow.h \
    include/MainWindow.h \
    include/Property.h \
    include/PropertySet.h \
    include/WindowFactory.h \
    include/Archives/FileSystemArchive.h \
    include/Archives/QtResArchive.h \
    include/Archives/ZipArchive.h \
    include/PropertyParserManager.h \
    include/PropertyParsers.h \
    include/PropertyTypes.h \
    include/RenderSystems/QtRenderSystem.h \
    include/RenderSystem.h

INCLUDEPATH += \
    include \
    include/Qt \
    boost_1_60_0

unix {
    target.path = /usr/lib
    INSTALLS += target
}
