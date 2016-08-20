#include <System.h>
#include <XmlParsers/QtXmlParser.h>

namespace duilib2
{

void System::createXmlParser()
{
	mXmlParser = new QtXmlParser;
}

}
