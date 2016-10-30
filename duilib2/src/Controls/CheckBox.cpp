#include <Controls/CheckBox.h>

namespace duilib2
{

static String gCheckBoxProperties[][3] =
{
	// name              value         type
	{"", "", ""}
};


String CheckBox::sTypeName = "CheckBox";

CheckBox::CheckBox(const String& name)
	: Option(name)
{
	String* property = &gCheckBoxProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

CheckBox::~CheckBox()
{

}

String CheckBox::getType() const
{
	return sTypeName;
}

int CheckBox::getWidth() const
{
	return 0;
}

int CheckBox::getHeight() const
{
	return 0;
}

Point CheckBox::getPosition() const
{
	return Point();
}

void CheckBox::render(RenderTarget* renderTarget)
{

}


CheckBoxFactory::CheckBoxFactory()
{

}

CheckBoxFactory::~CheckBoxFactory()
{

}

String CheckBoxFactory::getType() const
{
	return String("CheckBox");
}

Window* CheckBoxFactory::createInstance(const String& name)
{
	return new CheckBox(name);
}

void CheckBoxFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
