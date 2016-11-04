#include <Controls/DateTime.h>

namespace duilib2
{

static String gDateTimeProperties[][3] =
{
	// name              value         type
	{"", "", ""}
};


String DateTime::sTypeName = "DateTime";

DateTime::DateTime(const String& name)
	: Label(name)
{
	String* property = &gDateTimeProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

DateTime::~DateTime()
{

}

String DateTime::getType() const
{
	return sTypeName;
}

int DateTime::getWidth() const
{
	return 0;
}

int DateTime::getHeight() const
{
	return 0;
}

Point DateTime::getPosition() const
{
	return Point();
}

void DateTime::render()
{

}


DateTimeFactory::DateTimeFactory()
{

}

DateTimeFactory::~DateTimeFactory()
{

}

String DateTimeFactory::getType() const
{
	return String("DateTime");
}

Window* DateTimeFactory::createInstance(const String& name)
{
	return new DateTime(name);
}

void DateTimeFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
