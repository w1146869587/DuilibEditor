#include <Controls/ListBody.h>

namespace duilib2
{

static String gListBodyProperties[][3] =
{
	// name              value         type
	{"", "", ""}
};


String ListBody::sTypeName = "ListBody";

ListBody::ListBody(const String& name)
	: VerticalLayout(name)
{
	String* property = &gListBodyProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

ListBody::~ListBody()
{

}

String ListBody::getType() const
{
	return sTypeName;
}

int ListBody::getWidth() const
{
	return 0;
}

int ListBody::getHeight() const
{
	return 0;
}

Point ListBody::getPosition() const
{
	return Point();
}

void ListBody::render()
{

}


ListBodyFactory::ListBodyFactory()
{

}

ListBodyFactory::~ListBodyFactory()
{

}

String ListBodyFactory::getType() const
{
	return String("ListBody");
}

Window* ListBodyFactory::createInstance(const String& name)
{
	return new ListBody(name);
}

void ListBodyFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
