#include <LayoutXmlHandler.h>

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
	// 根据元素名称构造窗口控件实例，设置属性
	// WindowManager
	// WindowFactory
}

void LayoutXmlHandler::elementEnd(const String& element)
{

}

void LayoutXmlHandler::text(const String& text)
{

}

}
