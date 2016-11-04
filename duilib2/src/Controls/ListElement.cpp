#include <Controls/ListElement.h>

namespace duilib2
{

static String gListElementProperties[][3] =
{
	// name              value         type
	{"", "", ""}
};


String ListElement::sTypeName = "ListElement";

ListElement::ListElement(const String& name)
	: Control(name)
{
	String* property = &gListElementProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

ListElement::~ListElement()
{

}

String ListElement::getType() const
{
	return sTypeName;
}

int ListElement::getWidth() const
{
	return 0;
}

int ListElement::getHeight() const
{
	return 0;
}

Point ListElement::getPosition() const
{
	return Point();
}

void ListElement::render()
{

}


ListElementFactory::ListElementFactory()
{

}

ListElementFactory::~ListElementFactory()
{

}

String ListElementFactory::getType() const
{
	return String("ListElement");
}

Window* ListElementFactory::createInstance(const String& name)
{
	return new ListElement(name);
}

void ListElementFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
