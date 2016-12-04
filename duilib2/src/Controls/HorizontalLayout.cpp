#include <Controls/HorizontalLayout.h>

namespace duilib2
{

static String gHorizontalLayoutProperties[][3] =
{
	// name      value    type
	{"sepwidth", "0",     "Int"},
	{"sepimm",   "false", "Bool"},
	{"", "", ""}
};


String HorizontalLayout::sTypeName = "HorizontalLayout";

HorizontalLayout::HorizontalLayout(const String& name)
	: Container(name)
{
	String* property = &gHorizontalLayoutProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

HorizontalLayout::~HorizontalLayout()
{

}

String HorizontalLayout::getType() const
{
	return sTypeName;
}

int HorizontalLayout::getWidth() const
{
	int width = Container::getWidth();
	if (width == 0 && getParent())
		width = getParent()->getWidth();

	return width;
}

int HorizontalLayout::getHeight() const
{
	int height = Container::getHeight();
	if (height == 0 && getParent())
		height = getParent()->getHeight();

	return height;
}


HorizontalLayoutFactory::HorizontalLayoutFactory()
{

}

HorizontalLayoutFactory::~HorizontalLayoutFactory()
{

}

String HorizontalLayoutFactory::getType() const
{
	return String("HorizontalLayout");
}

Window* HorizontalLayoutFactory::createInstance(const String& name)
{
	return new HorizontalLayout(name);
}

void HorizontalLayoutFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
