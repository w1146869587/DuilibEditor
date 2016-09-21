#include <System.h>
#include <XmlParsers/QtXmlParser.h>
#include <Archives/FileSystemArchive.h>
#include <NativeWindows/QtMainWindow.h>

namespace duilib2
{

void System::createXmlParser()
{
	mXmlParser = new QtXmlParser;
}

void System::addArchiveFactories()
{
	mArchiveManager->addArchiveFactory(new FileSystemArchiveFactory);
	//mArchiveManager->addArchiveFactory(new ZipArchiveFactory);
	//mArchiveManager->addArchiveFactory(new QtResArchiveFactory);
}

void System::addWindowFactores()
{
	mWindowManager->addWindowFactory(new QtMainWindowFactory);
	// 其他窗口、控件类型
	// ...
}

void System::createRenderSystem()
{
	//mRenderSystem = new QtPainterRenderSystem;
}

}
