#include <Controls/WebBrowser.h>

namespace duilib2
{

static String gWebBrowserProperties[][3] =
{
	// name              value         type
	{"", "", ""}
};


String WebBrowser::sTypeName = "WebBrowser";

WebBrowser::WebBrowser(const String& name)
	: ActiveX(name)
{
	String* property = &gWebBrowserProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

WebBrowser::~WebBrowser()
{

}

String WebBrowser::getType() const
{
	return sTypeName;
}

int WebBrowser::getWidth() const
{
	return 0;
}

int WebBrowser::getHeight() const
{
	return 0;
}

Point WebBrowser::getPosition() const
{
	return Point();
}

void WebBrowser::render()
{

}


WebBrowserFactory::WebBrowserFactory()
{

}

WebBrowserFactory::~WebBrowserFactory()
{

}

String WebBrowserFactory::getType() const
{
	return String("WebBrowser");
}

Window* WebBrowserFactory::createInstance(const String& name)
{
	return new WebBrowser(name);
}

void WebBrowserFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
