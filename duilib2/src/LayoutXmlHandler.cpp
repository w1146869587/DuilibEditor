#include <LayoutXmlHandler.h>
#include <WindowManager.h>

namespace duilib2
{

LayoutXmlHandler::LayoutXmlHandler()
	: mRootWindow(NULL)
{

}

LayoutXmlHandler::~LayoutXmlHandler()
{

}

Window* LayoutXmlHandler::getLayoutRootWindow()
{
	return mRootWindow;
}

void LayoutXmlHandler::elementStart(const String& element, const XmlAttributes& attributes)
{
	Window* window = WindowManager::getSingleton().createWindow(element, attributes.getValue("name"));
	if (mRootWindow == NULL)
		mRootWindow = window;

	mStack.push(window);

	// 添加属性
	int count = attributes.getCount();
	for (int i = 0; i < count; ++i)
	{
		String name = attributes.getName(i);
		String value = attributes.getValue(i);
		window->addProperty(name, value);
	}
}

void LayoutXmlHandler::elementEnd(const String& /*element*/)
{
	mStack.pop();
}

void LayoutXmlHandler::text(const String& /*text*/)
{

}

}
