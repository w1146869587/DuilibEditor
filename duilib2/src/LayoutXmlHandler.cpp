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

}

void LayoutXmlHandler::elementEnd(const String& element)
{

}

void LayoutXmlHandler::text(const String& text)
{

}

}
