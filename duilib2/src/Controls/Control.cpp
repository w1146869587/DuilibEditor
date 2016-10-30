#include <Controls/Control.h>

namespace duilib2
{

static String gControlProperties[][3] =
{
	// name              value         type
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
	// 需要构建一个父窗口显示自己
	// ...
	return String();
}

int Control::getWidth() const
{
	return 0;
}

int Control::getHeight() const
{
	return 0;
}

Point Control::getPosition() const
{
	return Point();
}

void Control::render(RenderTarget* renderTarget)
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
