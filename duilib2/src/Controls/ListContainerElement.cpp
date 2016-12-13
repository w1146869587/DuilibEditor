#include <Controls/ListContainerElement.h>

namespace duilib2
{

static String gListContainerElementProperties[][3] =
{
	// name      value    type
	{"selected", "false", "Bool"},
	{"", "", ""}
};


String ListContainerElement::sTypeName = "ListContainerElement";

ListContainerElement::ListContainerElement(const String& name)
	: Container(name)
{
	String* property = &gListContainerElementProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

ListContainerElement::~ListContainerElement()
{

}

String ListContainerElement::getType() const
{
	return sTypeName;
}

int ListContainerElement::getWidth() const
{
	return 0;
}

int ListContainerElement::getHeight() const
{
	return 0;
}

Point ListContainerElement::getPosition() const
{
	return Point();
}


ListContainerElementFactory::ListContainerElementFactory()
{

}

ListContainerElementFactory::~ListContainerElementFactory()
{

}

String ListContainerElementFactory::getType() const
{
	return String("ListContainerElement");
}

Window* ListContainerElementFactory::createInstance(const String& name)
{
	return new ListContainerElement(name);
}

void ListContainerElementFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
