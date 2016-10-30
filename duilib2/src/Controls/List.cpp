#include <Controls/List.h>

namespace duilib2
{

static String gListProperties[][3] =
{
	// name              value         type
	{"", "", ""}
};


String List::sTypeName = "List";

List::List(const String& name)
	: VerticalLayout(name)
{
	String* property = &gListProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

List::~List()
{

}

String List::getType() const
{
	return sTypeName;
}

int List::getWidth() const
{
	return 0;
}

int List::getHeight() const
{
	return 0;
}

Point List::getPosition() const
{
	return Point();
}

void List::render(RenderTarget* renderTarget)
{

}


ListFactory::ListFactory()
{

}

ListFactory::~ListFactory()
{

}

String ListFactory::getType() const
{
	return String("List");
}

Window* ListFactory::createInstance(const String& name)
{
	return new List(name);
}

void ListFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
