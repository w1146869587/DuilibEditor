#include <Controls/TabLayout.h>

namespace duilib2
{

static String gTabLayoutProperties[][3] =
{
	// name        value  type
	{"selectedid", "0",   "Int"},
	{"", "", ""}
};


String TabLayout::sTypeName = "TabLayout";

TabLayout::TabLayout(const String& name)
	: Container(name)
{
	String* property = &gTabLayoutProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

TabLayout::~TabLayout()
{

}

String TabLayout::getType() const
{
	return sTypeName;
}

int TabLayout::getWidth() const
{
	return 0;
}

int TabLayout::getHeight() const
{
	return 0;
}

Point TabLayout::getPosition() const
{
	return Point();
}


TabLayoutFactory::TabLayoutFactory()
{

}

TabLayoutFactory::~TabLayoutFactory()
{

}

String TabLayoutFactory::getType() const
{
	return String("TabLayout");
}

Window* TabLayoutFactory::createInstance(const String& name)
{
	return new TabLayout(name);
}

void TabLayoutFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
