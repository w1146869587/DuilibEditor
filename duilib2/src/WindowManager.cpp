#include <WindowManager.h>
#include <ResourceManager.h>
#include <LayoutXmlHandler.h>
#include <System.h>
#include <Exception.h>
#include <algorithm>

namespace duilib2
{

WindowManager* Singleton<WindowManager>::mSingleton = NULL;

WindowManager::WindowManager()
{

}

WindowManager::~WindowManager()
{
	destroyAllWindows();
	removeAllWindowFactories();
}

void WindowManager::addWindowFactory(WindowFactory* factory)
{
	mWindowFactories[factory->getType()] = factory;
}

void WindowManager::removeWindowFactory(const String& type)
{
	mWindowFactories.erase(type);
}

void WindowManager::removeWindowFactory(WindowFactory* factory)
{
	String type = factory->getType();
	removeWindowFactory(type);
}

void WindowManager::removeAllWindowFactories()
{
	WindowFactoryMap::iterator iter = mWindowFactories.begin();
	while (iter != mWindowFactories.end())
	{
		mWindowFactories.erase(iter);
		iter = mWindowFactories.begin();
	}
}

Window* WindowManager::createWindow(const String& name, const String& type)
{
	WindowFactoryMap::iterator pos = mWindowFactories.find(type);
	if (pos == mWindowFactories.end())
	{
		DUILIB2_EXCEPT(Exception::ERR_ITEM_NOT_FOUND,
							 "Window factory named" + name + "is not exists",
							 "WindowManager::createWindow");
	}

	Window* window = pos->second->createInstance(name);
	if (window)
		mWindows.push_back(window);

	return window;
}

void WindowManager::destroyWindow(Window* window)
{
	// destroy children first
	std::vector<Window*> children = window->getChildren();
	for (int i = 0; i < (int)children.size(); ++i)
	{
		destroyWindow(children[i]);
	}


	String type = window->getType();

	WindowFactoryMap::iterator pos = mWindowFactories.find(type);
	if (pos == mWindowFactories.end())
	{
		DUILIB2_EXCEPT(Exception::ERR_ITEM_NOT_FOUND,
							 "Window factory named" + type + "is not exists",
							 "WindowManager::createWindow");
	}

	pos->second->destroyInstance(window);
	std::vector<Window*>::iterator posWin = std::find(mWindows.begin(), mWindows.end(), window);
	if (posWin != mWindows.end())
		mWindows.erase(posWin);
}

void WindowManager::destroyAllWindows()
{
	// 因为destroyWindow()函数中在mWindows成员中移除了一个成员（对容器的修改将导致迭代器实效）
	// 所以此处destroyWindow()之后需要重新获得迭代器
	std::vector<Window*>::iterator iter = mWindows.begin();
	while (iter != mWindows.end())
	{
		destroyWindow(*iter);
		iter = mWindows.begin();
	}
}

Window* WindowManager::loadLayoutFromFile(const String& fileName)
{
	RawDataContainerPtr rawData = ResourceManager::getSingleton().getFileRawData(fileName);

	LayoutXmlHandler xmlHandler;
	XmlParser* parser = System::getSingleton().getXmlParser();
	parser->parseXml(xmlHandler, *rawData.get());

	return xmlHandler.getLayoutRootWindow();
}


} // namespace duilib2
