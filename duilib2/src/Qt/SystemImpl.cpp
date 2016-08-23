#include <System.h>
#include <XmlParsers/QtXmlParser.h>
#include <FileSystemArchive.h>

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

}
