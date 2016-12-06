#include <Controls/VerticalLayout.h>

namespace duilib2
{

static String gVerticalLayoutProperties[][3] =
{
	// name       value    type
	{"sepheight", "0",     "Int"},
	{"sepimm",    "false", "Bool"},
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
	int width = Container::getWidth();
	if (width == 0 && getParent())
		width = getParent()->getWidth();

	return width;
}

int VerticalLayout::getHeight() const
{
	int height = Container::getHeight();
	if (height == 0 && getParent())
		height = getParent()->getHeight();

	return height;
}

void VerticalLayout::updateLayout()
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
