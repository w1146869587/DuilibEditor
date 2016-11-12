#include <LayoutXmlHandler.h>
#include <WindowManager.h>
#include <FontManager.h>
#include <DefaultPropertyManager.h>

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
	if (element == "Font")
		FontElementStart(attributes);
	else if (element == "Default")
		DefaultElementStart(attributes);
	else
	{
		Window* window = WindowManager::getSingleton().createWindow(element, attributes.getValue("name"));
		if (mRootWindow == NULL)
			mRootWindow = window;

		// 设置父窗口
		if (!mStack.empty())
		{
			Window* parent = mStack.top();
			window->setParent(parent);
		}

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
}

void LayoutXmlHandler::elementEnd(const String& element)
{
	if (element == "Font" || element == "Default")
		return;

	mStack.pop();
}

void LayoutXmlHandler::text(const String& /*text*/)
{

}

void LayoutXmlHandler::FontElementStart(const XmlAttributes& attributes)
{
	Font font;

	int count = attributes.getCount();
	for (int i = 0; i < count; ++i)
	{
		String name = attributes.getName(i);
		String value = attributes.getValue(i);
		font.setProperty(name, value);
	}

	FontManager* fontManager = FontManager::getSingletonPtr();
	fontManager->addFont(font);
}

void LayoutXmlHandler::DefaultElementStart(const XmlAttributes& attributes)
{
	DefaultProperty defaultProperty;

	int count = attributes.getCount();
	for (int i = 0; i < count; ++i)
	{
		String name = attributes.getName(i);
		String value = attributes.getValue(i);
		defaultProperty.setProperty(name, value);
	}

	DefaultPropertyManager* manager = DefaultPropertyManager::getSingletonPtr();
	manager->addDefaultProperty(defaultProperty);
}

}
