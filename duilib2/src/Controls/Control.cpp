#include <Controls/Control.h>
#include <RenderSystemProxy.h>

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
	// if (getParent())
	//     getParent()->showModal();
	// else
	// 需要构建一个父窗口显示自己
	// ...
	return String();
}

int Control::getWidth() const
{
	return getProperty("width").getAnyValue<Int>();
}

int Control::getHeight() const
{
	return getProperty("height").getAnyValue<Int>();
}

Point Control::getPosition(bool relativeToMainWindow) const
{
	Rect posProperty = getProperty("pos").getAnyValue<Rect>();
	Point pos(posProperty.mLeft, posProperty.mTop);

	if (relativeToMainWindow && getParent())
	{
		Point posParent = getParent()->getPosition(true);
		pos.mX += posParent.mX;
		pos.mY += posParent.mY;
	}

	return pos;
}

void Control::render()
{
	RenderTarget* rt = getRenderTarget();
	if (rt == NULL)
		return;

	RenderSystemProxy rs(rt);

	// setup clip region
	//rs.setClipRegion(...);

	drawBackgroundColor(&rs);
	drawBackgroundImage(&rs);
	drawStatusImage(&rs);
	drawText(&rs);
	drawBorder(&rs);

	Window::render();
}

void Control::drawBackgroundColor(RenderSystem* /*rs*/)
{

}

void Control::drawBackgroundImage(RenderSystem* /*rs*/)
{

}

void Control::drawStatusImage(RenderSystem* /*rs*/)
{

}

void Control::drawText(RenderSystem* /*rs*/)
{

}

void Control::drawBorder(RenderSystem* /*rs*/)
{

}

ControlFactory::ControlFactory()
{

}

ControlFactory::~ControlFactory()
{

}

String ControlFactory::getType() const
{
	return String("Control");
}

Window* ControlFactory::createInstance(const String& name)
{
	return new Control(name);
}

void ControlFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
