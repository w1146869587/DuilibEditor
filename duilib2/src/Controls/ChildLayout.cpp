#include <Controls/ChildLayout.h>

namespace duilib2
{

static String gChildLayoutProperties[][3] =
{
	// name              value         type
	{"", "", ""}
};


String ChildLayout::sTypeName = "ChildLayout";

ChildLayout::ChildLayout(const String& name)
	: Container(name)
{
	String* property = &gChildLayoutProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

ChildLayout::~ChildLayout()
{

}

String ChildLayout::getType() const
{
	return sTypeName;
}

int ChildLayout::getWidth() const
{
	return 0;
}

int ChildLayout::getHeight() const
{
	return 0;
}

Point ChildLayout::getPosition() const
{
	return Point();
}


ChildLayoutFactory::ChildLayoutFactory()
{

}

ChildLayoutFactory::~ChildLayoutFactory()
{

}

String ChildLayoutFactory::getType() const
{
	return String("ChildLayout");
}

Window* ChildLayoutFactory::createInstance(const String& name)
{
	return new ChildLayout(name);
}

void ChildLayoutFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
