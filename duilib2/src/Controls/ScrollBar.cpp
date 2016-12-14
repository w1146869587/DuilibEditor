#include <Controls/ScrollBar.h>

namespace duilib2
{

static String gScrollBarProperties[][3] =
{
	// name                  value   type
	{"button1normalimage",   "",     "Image"},
	{"button1hotimage",      "",     "Image"},
	{"button1pushedimage",   "",     "Image"},
	{"button1disabledimage", "",     "Image"},
	{"button2normalimage",   "",     "Image"},
	{"button2hotimage",      "",     "Image"},
	{"button2pushedimage",   "",     "Image"},
	{"button2disabledimage", "",     "Image"},
	{"thumbnormalimage",     "",     "Image"},
	{"thumbhotimage",        "",     "Image"},
	{"thumbpushedimage",     "",     "Image"},
	{"thumbdisabledimage",   "",     "Image"},
	{"railnormalimage",      "",     "Image"},
	{"railhotimage",         "",     "Image"},
	{"railpushedimage",      "",     "Image"},
	{"raildisabledimage",    "",     "Image"},
	{"bknormalimage",        "",     "Image"},
	{"bkhotimage",           "",     "Image"},
	{"bkpushedimage",        "",     "Image"},
	{"bkdisabledimage",      "",     "Image"},
	{"hor",                  "true", "Bool"},
	{"linesize",             "8",    "Int"},
	{"range",                "100",  "Int"},
	{"value",                "0",    "Int"},
	{"showbutton1",          "true", "Bool"},
	{"showbutton2",          "true", "Bool"},
	{"", "", ""}
};


String ScrollBar::sTypeName = "ScrollBar";

ScrollBar::ScrollBar(const String& name)
	: Control(name)
{
	String* property = &gScrollBarProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

ScrollBar::~ScrollBar()
{

}

String ScrollBar::getType() const
{
	return sTypeName;
}

int ScrollBar::getWidth() const
{
	return 0;
}

int ScrollBar::getHeight() const
{
	return 0;
}

Point ScrollBar::getPosition() const
{
	return Point();
}


ScrollBarFactory::ScrollBarFactory()
{

}

ScrollBarFactory::~ScrollBarFactory()
{

}

String ScrollBarFactory::getType() const
{
	return String("ScrollBar");
}

Window* ScrollBarFactory::createInstance(const String& name)
{
	return new ScrollBar(name);
}

void ScrollBarFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
