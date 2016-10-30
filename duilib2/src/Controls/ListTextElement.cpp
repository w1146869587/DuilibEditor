#include <Controls/ListTextElement.h>

namespace duilib2
{

static String gListTextElementProperties[][3] =
{
	// name              value         type
	{"", "", ""}
};


String ListTextElement::sTypeName = "ListTextElement";

ListTextElement::ListTextElement(const String& name)
	: ListLabelElement(name)
{
	String* property = &gListTextElementProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

ListTextElement::~ListTextElement()
{

}

String ListTextElement::getType() const
{
	return sTypeName;
}

int ListTextElement::getWidth() const
{
	return 0;
}

int ListTextElement::getHeight() const
{
	return 0;
}

Point ListTextElement::getPosition() const
{
	return Point();
}

void ListTextElement::render(RenderTarget* renderTarget)
{

}


ListTextElementFactory::ListTextElementFactory()
{

}

ListTextElementFactory::~ListTextElementFactory()
{

}

String ListTextElementFactory::getType() const
{
	return String("ListTextElement");
}

Window* ListTextElementFactory::createInstance(const String& name)
{
	return new ListTextElement(name);
}

void ListTextElementFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
