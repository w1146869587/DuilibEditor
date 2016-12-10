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
	int totalWidth = getWidth();
	int controlPadding = getChildPadding();
	int controlHeight = getControlHeight();
	int currentPosY = 0;

	std::vector<Window*> children = getChildren();
	for (int i = 0; i < children.size(); ++i)
	{
		Control* control = dynamic_cast<Control*>(children[i]);
		if (control == NULL || control->isFloat())
			continue;

		int height = control->getProperty("height").getAnyValue<int>();
		int offsetY = height;
		if (height == 0)
		{
			control->_setHeight(controlHeight);
			offsetY = controlHeight;
		}

		int posX(0);
		int width = control->getProperty("width").getAnyValue<int>();
		if (width == 0)
			control->_setWidth(totalWidth);
		else
			posX = (totalWidth - width) / 2.0;

		control->_setPosition(Point(posX, currentPosY));

		currentPosY += offsetY + controlPadding;
	}
}

int VerticalLayout::getControlHeight() const
{
	int count(0);
	int knownHeight(0);
	std::vector<Window*> children = getChildren();
	for (int i = 0; i < children.size(); ++i)
	{
		Control* control = dynamic_cast<Control*>(children[i]);
		if (control == NULL || control->isFloat())
			continue;

		int height = control->getProperty("height").getAnyValue<int>();
		if (height == 0)
			++count;
		else
			knownHeight += height;
	}

	int totalHeight = getHeight();
	int controlPadding = getChildPadding() * (children.size() - 1);
	int controlHeight = (totalHeight - knownHeight - controlPadding) / count;
	if (controlHeight < 0)
		controlHeight = 0;

	return controlHeight;
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
