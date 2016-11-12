#include <Controls/Text.h>

namespace duilib2
{

static String gTextProperties[][3] =
{
	// name              value         type
	{"", "", ""}
};


String Text::sTypeName = "Text";

Text::Text(const String& name)
	: Label(name)
{
	String* property = &gTextProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

Text::~Text()
{

}

String Text::getType() const
{
	return sTypeName;
}

int Text::getWidth() const
{
	return 0;
}

int Text::getHeight() const
{
	return 0;
}

Point Text::getPosition() const
{
	return Point();
}


TextFactory::TextFactory()
{

}

TextFactory::~TextFactory()
{

}

String TextFactory::getType() const
{
	return String("Text");
}

Window* TextFactory::createInstance(const String& name)
{
	return new Text(name);
}

void TextFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
