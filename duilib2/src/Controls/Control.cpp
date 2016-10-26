#include <Controls/Control.h>

namespace duilib2
{

static String gControlProperties[][3] =
{
	// name              value         type
	{"name",             "",           "String"},
	{"pos",              "0,0,0,0",    "Rect"},
	{"padding",          "0,0,0,0",    "Rect"},
	{"bkcolor",          "0x00000000", "Color"},
	{"bkcolor2",         "0x00000000", "Color"},
	{"bkcolor3",         "0x00000000", "Color"},
	{"bordercolor",      "0x00000000", "Color"},
	{"focusbordercolor", "0x00000000", "Color"},
	{"colorhsl",         "false",      "Bool"},
	{"bordersize",       "0",          "Rect"},
	{"leftbordersize",   "0",          "Int"},
	{"topbordersize",    "0",          "Int"},
	{"rightbordersize",  "0",          "Int"},
	{"bottombordersize", "0",          "Int"},
	{"borderstyle",      "0",          "Int"},
	{"borderround",      "0,0",        "Size"},
	{"bkimage",          "",           "String"},
	{"width",            "0",          "Int"},
	{"height",           "0",          "Int"},
	{"minwidth",         "0",          "Int"},
	{"minheight",        "0",          "Int"},
	{"maxwidth",         "9999",       "Int"},
	{"maxheight",        "9999",       "Int"},
	{"text",             "",           "String"},
	{"tooltip",          "",           "String"},
	{"userdata",         "",           "String"},
	{"enabled",          "true",       "Bool"},
	{"mouse",            "true",       "Bool"},
	{"visible",          "true",       "Bool"},
	{"float",            "false",      "Bool"},
	{"shortcut",         "",           "String"},
	{"menu",             "false",      "Bool"},
	{"keyboard",         "true",       "Bool"},
	{"", "", ""}
};


String Control::sTypeName = "Control";

Control::Control(const String& name)
	: Window(name)
{
	String* property = &gControlProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

Control::~Control()
{

}

String Control::getType() const
{
	return sTypeName;
}

String Control::showModal()
{
	// 控件无法显示自己必须有一个顶层的MainWindow
	// 如果控件没有MainWindow父窗口，需要创建一个，并显示该MainWindow
	// MainWindow需要重写该函数
	// ToDo
	// ...
	return String();
}

int Control::getWidth() const
{

}

int Control::getHeight() const
{

}

Point Control::getPosition() const
{

}

void Control::render(RenderTarget* renderTarget)
{

}


} // namespace duilib2
