#include <Controls/ScrollBar.h>

namespace duilib2
{

static String gScrollBarProperties[][3] =
{
	// name              value         type
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

void ScrollBar::render()
{

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
