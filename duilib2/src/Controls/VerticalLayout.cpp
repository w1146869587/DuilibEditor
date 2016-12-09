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
	// float类型的控件不受布局管理
	// 总高度减去定义了高度的所有控件高度之和
	// 然后除以剩余的未定义高度的控件个数，则为每个控件的高度
	// 这样所有控件的高度就知道了
	// 而宽度是：未定义宽度的取当前布局的宽度
	// 依次确定各个控件的位置，设置到控件

	int controlHeight = getControlHeight();
	// ...

}

int VerticalLayout::getControlHeight() const
{
	int count(0);
	int knownHeight(0);
	std::vector<Window*> children = getChildren();
	for (int i = 0; i < children.size(); ++i)
	{
		Control* control = dynamic_cast<Control*>(children[i]);
		if (control == NULL)
			continue;

		if (control->isFloat())
			continue;

		int height = control->getProperty("height").getAnyValue<int>();
		if (height == 0)
		{
			++count;
		}
		else
		{
			knownHeight += height;
		}
	}

	int totalHeight = getHeight();
	int controlPadding = getChildPadding() * (children.size() - 1);
	int controlHeight = (totalHeight - knownHeight - controlPadding) / count;
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
