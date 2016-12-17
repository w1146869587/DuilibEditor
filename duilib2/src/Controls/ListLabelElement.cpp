#include <Controls/ListLabelElement.h>

namespace duilib2
{

static String gListLabelElementProperties[][3] =
{
	// name      value    type
	{"selected", "false", "Bool"},
	{"", "", ""}
};


String ListLabelElement::sTypeName = "ListLabelElement";

ListLabelElement::ListLabelElement(const String& name)
	: ListElement(name)
{
	String* property = &gListLabelElementProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

ListLabelElement::~ListLabelElement()
{

}

String ListLabelElement::getType() const
{
	return sTypeName;
}

int ListLabelElement::getWidth() const
{
	return 0;
}

int ListLabelElement::getHeight() const
{
	return 0;
}

Point ListLabelElement::getPosition() const
{
	return Point();
}


ListLabelElementFactory::ListLabelElementFactory()
{

}

ListLabelElementFactory::~ListLabelElementFactory()
{

}

String ListLabelElementFactory::getType() const
{
	return String("ListLabelElement");
}

Window* ListLabelElementFactory::createInstance(const String& name)
{
	return new ListLabelElement(name);
}

void ListLabelElementFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
