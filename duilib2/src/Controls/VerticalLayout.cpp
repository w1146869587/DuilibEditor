#include <Controls/VerticalLayout.h>

namespace duilib2
{

static String gVerticalLayoutProperties[][3] =
{
	// name              value         type
	{"", "", ""}
};


String VerticalLayout::sTypeName = "VerticalLayout";

VerticalLayout::VerticalLayout(const String& name)
	: Container(name)
{
	String* property = &gVerticalLayoutProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

VerticalLayout::~VerticalLayout()
{

}

String VerticalLayout::getType() const
{
	return sTypeName;
}

int VerticalLayout::getWidth() const
{
	return 0;
}

int VerticalLayout::getHeight() const
{
	return 0;
}

Point VerticalLayout::getPosition() const
{
	return Point();
}

void VerticalLayout::render()
{

}


VerticalLayoutFactory::VerticalLayoutFactory()
{

}

VerticalLayoutFactory::~VerticalLayoutFactory()
{

}

String VerticalLayoutFactory::getType() const
{
	return String("VerticalLayout");
}

Window* VerticalLayoutFactory::createInstance(const String& name)
{
	return new VerticalLayout(name);
}

void VerticalLayoutFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
