#include <Controls/Option.h>

namespace duilib2
{

static String gOptionProperties[][3] =
{
	// name               value         type
	{"selectedimage",     "",           "Image"},
	{"foreimage",         "",           "Image"},
	{"selectedtextcolor", "0x00000000", "Color"},
	{"group",             "",           "String"},
	{"selected",          "false",      "Bool"},
	{"", "", ""}
};


String Option::sTypeName = "Option";

Option::Option(const String& name)
	: Button(name)
{
	String* property = &gOptionProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

Option::~Option()
{

}

String Option::getType() const
{
	return sTypeName;
}

int Option::getWidth() const
{
	return 0;
}

int Option::getHeight() const
{
	return 0;
}

Point Option::getPosition() const
{
	return Point();
}

void Option::render()
{

}


OptionFactory::OptionFactory()
{

}

OptionFactory::~OptionFactory()
{

}

String OptionFactory::getType() const
{
	return String("Option");
}

Window* OptionFactory::createInstance(const String& name)
{
	return new Option(name);
}

void OptionFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
