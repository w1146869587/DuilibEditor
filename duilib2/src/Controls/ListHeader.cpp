#include <Controls/ListHeader.h>

namespace duilib2
{

static String gListHeaderProperties[][3] =
{
	// name              value         type
	{"", "", ""}
};


String ListHeader::sTypeName = "ListHeader";

ListHeader::ListHeader(const String& name)
	: HorizontalLayout(name)
{
	String* property = &gListHeaderProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

ListHeader::~ListHeader()
{

}

String ListHeader::getType() const
{
	return sTypeName;
}

int ListHeader::getWidth() const
{
	return 0;
}

int ListHeader::getHeight() const
{
	return 0;
}

Point ListHeader::getPosition() const
{
	return Point();
}


ListHeaderFactory::ListHeaderFactory()
{

}

ListHeaderFactory::~ListHeaderFactory()
{

}

String ListHeaderFactory::getType() const
{
	return String("ListHeader");
}

Window* ListHeaderFactory::createInstance(const String& name)
{
	return new ListHeader(name);
}

void ListHeaderFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
