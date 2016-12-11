#include "System.h"

namespace duilib2
{

System* Singleton<System>::mSingleton = NULL;

System::System()
	: mArchiveManager(0)
	, mResourceManager(0)
	, mWindowManager(0)
	, mPropertyParserManager(0)
	, mXmlParser(0)
	, mRenderSystem(0)
	, mFontManager(0)
	, mDefaultPropertyManager(0)
{
	mArchiveManager = new ArchiveManager;
	mResourceManager = new ResourceManager;
	mWindowManager = new WindowManager;
	mPropertyParserManager = new PropertyParserManager;
	mFontManager = new FontManager;
	mDefaultPropertyManager = new DefaultPropertyManager;

	createXmlParser();
	createRenderSystem();
	addArchiveFactories();
	addWindowFactores();
}

System::~System()
{
	delete mRenderSystem;
	delete mXmlParser;
	delete mPropertyParserManager;
	delete mWindowManager;
	delete mResourceManager;
	delete mArchiveManager;
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
