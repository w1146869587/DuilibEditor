#include <WindowManager.h>

namespace duilib2
{

WindowManager* Singleton<WindowManager>::mSingleton = NULL;

WindowManager::WindowManager()
{

}

WindowManager::~WindowManager()
{

}

Window* WindowManager::loadLayoutFromFile(const String& fileName)
{

//	RawDataContainerPtr rawData = ResourceManager::getSingleton().getFileRawData(fileName);

//	TestXmlHandler handler;
//	QtXmlParser parser;
//	parser.parseXml(handler, *rawData.get());

	return NULL;
}


} // namespace duilib2
