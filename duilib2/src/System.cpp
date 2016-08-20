#include "System.h"

namespace duilib2
{

System* Singleton<System>::mSingleton = NULL;

System::System()
	: mXmlParser(0)
{
	// 初始化ResourceManager等

	mResourceManager = new ResourceManager;
	mWindowManager = new WindowManager;

	createXmlParser();
}

System::~System()
{
	delete mWindowManager;
	delete mResourceManager;
	delete mXmlParser;
}

System* System::create()
{
	return new System();
}

void System::destroy()
{
	delete mSingleton;
}

XmlParser* System::getXmlParser() const
{
	return mXmlParser;
}

} // duilib2
