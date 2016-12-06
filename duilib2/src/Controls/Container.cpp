#include <Controls/Container.h>

namespace duilib2
{

static String gContainerProperties[][3] =
{
	// name           value       type
	{"mousechild",    "true",     "Bool"},
	{"inset",         "0,0,0,0",  "Rect"},
	{"vscrollbar",    "false",    "Bool"},
	{"hscrollbar",    "false",    "Bool"},
	{"childpadding",  "0",        "Int"},
	{"", "", ""}
};


String Container::sTypeName = "Container";

Container::Container(const String& name)
	: Control(name)
{
	String* property = &gContainerProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

Container::~Container()
{

}

String Container::getType() const
{
	return sTypeName;
}

int Container::getChildPadding() const
{
	return getProperty("childpadding").getAnyValue<Int>();
}

void Container::render()
{
	updateLayout();
	Control::render();
}

void Container::updateLayout()
{
}


ContainerFactory::ContainerFactory()
{

}

ContainerFactory::~ContainerFactory()
{

}

String ContainerFactory::getType() const
{
	return String("Container");
}

Window* ContainerFactory::createInstance(const String& name)
{
	return new Container(name);
}

void ContainerFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
