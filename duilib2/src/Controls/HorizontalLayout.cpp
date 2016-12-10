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

void HorizontalLayout::updateLayout()
{
	int totalHeight = getHeight();
	int controlPadding = getChildPadding();
	int controlWidth = getControlWidth();
	int currentPosX = 0;

	std::vector<Window*> children = getChildren();
	for (int i = 0; i < children.size(); ++i)
	{
		Control* control = dynamic_cast<Control*>(children[i]);
		if (control == NULL || control->isFloat())
			continue;

		int width = control->getProperty("width").getAnyValue<int>();
		int offsetX = width;
		if (width == 0)
		{
			control->_setWidth(controlWidth);
			offsetX = controlWidth;
		}

		int posY(0);
		int height = control->getProperty("height").getAnyValue<int>();
		if (height == 0)
			control->_setHeight(totalHeight);
		else
			posY = (totalHeight - height) / 2.0;

		control->_setPosition(Point(currentPosX, posY));
		currentPosX += offsetX + controlPadding;
	}
}

int HorizontalLayout::getControlWidth() const
{
	int count(0);
	int unfloatCount(0);
	int knownWidth(0);
	std::vector<Window*> children = getChildren();
	for (int i = 0; i < children.size(); ++i)
	{
		Control* control = dynamic_cast<Control*>(children[i]);
		if (control == NULL || control->isFloat())
			continue;

		++unfloatCount;

		int width = control->getProperty("width").getAnyValue<int>();
		if (width == 0)
			++count;
		else
			knownWidth += width;
	}

	if (count == 0)
		return 0;

	int totalWidth = getWidth();
	int controlPadding = getChildPadding() * (unfloatCount - 1);
	int controlWidth = (totalWidth - knownWidth - controlPadding) / count;
	if (controlWidth < 0)
		controlWidth = 0;

	return controlWidth;
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
