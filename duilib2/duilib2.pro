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
    src/RenderSystem.cpp \
    src/RenderTargets/QtPaintDeviceRenderTarget.cpp \
    src/RenderTarget.cpp \
    src/RenderSystems/QtPainterRenderSystem.cpp \
    src/Controls/ActiveX.cpp \
    src/Controls/Button.cpp \
    src/Controls/CheckBox.cpp \
    src/Controls/ChildLayout.cpp \
    src/Controls/Combo.cpp \
    src/Controls/Container.cpp \
    src/Controls/Control.cpp \
    src/Controls/DateTime.cpp \
    src/Controls/Edit.cpp \
    src/Controls/GifAnim.cpp \
    src/Controls/HorizontalLayout.cpp \
    src/Controls/Label.cpp \
    src/Controls/List.cpp \
    src/Controls/ListBody.cpp \
    src/Controls/ListContainerElement.cpp \
    src/Controls/ListElement.cpp \
    src/Controls/ListHeader.cpp \
    src/Controls/ListHeaderItem.cpp \
    src/Controls/ListLabelElement.cpp \
    src/Controls/ListTextElement.cpp \
    src/Controls/Option.cpp \
    src/Controls/Progress.cpp \
    src/Controls/RichEdit.cpp \
    src/Controls/ScrollBar.cpp \
    src/Controls/Slider.cpp \
    src/Controls/TabLayout.cpp \
    src/Controls/Text.cpp \
    src/Controls/TileLayout.cpp \
    src/Controls/TreeNode.cpp \
    src/Controls/TreeView.cpp \
    src/Controls/VerticalLayout.cpp \
    src/Controls/WebBrowser.cpp \
    src/RoundRect.cpp \
    src/Event.cpp \
    src/EventSet.cpp \
    src/EventArgs.cpp \
    src/Types.cpp \
    src/DefaultProperty.cpp \
    src/DefaultPropertyManager.cpp \
    src/Font.cpp \
    src/FontManager.cpp \
    src/RenderSystemImpl.cpp \
    src/Image.cpp

HEADERS +=\
    include/System.h \
    include/Singleton.h \
    include/duilib2.h \
    include/Window.h \
    include/WindowManager.h \
    include/ResourceManager.h \
    include/Qt/duilib2_global.h \
    include/XmlHandler.h \
    include/XmlParser.h \
    include/RawDataContainer.h \
    include/XmlAttributes.h \
    include/Archive.h \
    include/ArchiveFactory.h \
    include/ArchiveManager.h \
    include/Exception.h \
    include/LayoutXmlHandler.h \
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
    include/RenderSystem.h \
    include/RenderTarget.h \
    include/Controls/ActiveX.h \
    include/Controls/Button.h \
    include/Controls/CheckBox.h \
    include/Controls/ChildLayout.h \
    include/Controls/Combo.h \
    include/Controls/Container.h \
    include/Controls/Control.h \
    include/Controls/DateTime.h \
    include/Controls/Edit.h \
    include/Controls/GifAnim.h \
    include/Controls/HorizontalLayout.h \
    include/Controls/Label.h \
    include/Controls/List.h \
    include/Controls/ListBody.h \
    include/Controls/ListContainerElement.h \
    include/Controls/ListElement.h \
    include/Controls/ListHeader.h \
    include/Controls/ListHeaderItem.h \
    include/Controls/ListLabelElement.h \
    include/Controls/ListTextElement.h \
    include/Controls/Option.h \
    include/Controls/Progress.h \
    include/Controls/RichEdit.h \
    include/Controls/ScrollBar.h \
    include/Controls/Slider.h \
    include/Controls/TabLayout.h \
    include/Controls/Text.h \
    include/Controls/TileLayout.h \
    include/Controls/TreeNode.h \
    include/Controls/TreeView.h \
    include/Controls/VerticalLayout.h \
    include/Controls/WebBrowser.h \
    include/RoundRect.h \
    include/Event.h \
    include/EventSet.h \
    include/EventArgs.h \
    include/Types.h \
    include/DefaultProperty.h \
    include/DefaultPropertyManager.h \
    include/Font.h \
    include/FontManager.h \
    src/NativeWindows/QtMainWindow.h \
    src/RenderSystems/QtPainterRenderSystem.h \
    src/RenderTargets/QtPaintDeviceRenderTarget.h \
    src/XmlParsers/QtXmlParser.h \
    include/RenderSystemImpl.h \
    include/Image.h

INCLUDEPATH += \
    include \
    include/Qt \
    boost_1_60_0

unix {
    target.path = /usr/lib
    INSTALLS += target
}
