#include "System.h"

namespace duilib2
{

System* Singleton<System>::mSingleton = NULL;

System::System()
	: mXmlParser(0)
{
	// 初始化ResourceManager等

	mArchiveManager = new ArchiveManager;
	mResourceManager = new ResourceManager;
	mWindowManager = new WindowManager;
	mPropertyParserManager = new PropertyParserManager;

	addArchiveFactories();
	createXmlParser();

}

System::~System()
{
	delete mPropertyParserManager;
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

RenderSystem* System::getRenderSystem() const
{
	return mRenderSystem;
}

} // duilib2
