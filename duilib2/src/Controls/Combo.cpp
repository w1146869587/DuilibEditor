#include <Controls/Combo.h>

namespace duilib2
{

static String gComboProperties[][3] =
{
	// name              value         type
	{"", "", ""}
};


String Combo::sTypeName = "Combo";

Combo::Combo(const String& name)
	: Container(name)
{
	String* property = &gComboProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

Combo::~Combo()
{

}

String Combo::getType() const
{
	return sTypeName;
}

int Combo::getWidth() const
{
	return 0;
}

int Combo::getHeight() const
{
	return 0;
}

Point Combo::getPosition() const
{
	return Point();
}

void Combo::render()
{

}


ComboFactory::ComboFactory()
{

}

ComboFactory::~ComboFactory()
{

}

String ComboFactory::getType() const
{
	return String("Combo");
}

Window* ComboFactory::createInstance(const String& name)
{
	return new Combo(name);
}

void ComboFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
