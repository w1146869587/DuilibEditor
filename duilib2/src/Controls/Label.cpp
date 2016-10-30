#include <Controls/Label.h>

namespace duilib2
{

static String gLabelProperties[][3] =
{
	// name              value         type
	{"", "", ""}
};


String Label::sTypeName = "Label";

Label::Label(const String& name)
	: Control(name)
{
	String* property = &gLabelProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

Label::~Label()
{

}

String Label::getType() const
{
	return sTypeName;
}

int Label::getWidth() const
{
	return 0;
}

int Label::getHeight() const
{
	return 0;
}

Point Label::getPosition() const
{
	return Point();
}

void Label::render(RenderTarget* renderTarget)
{

}


LabelFactory::LabelFactory()
{

}

LabelFactory::~LabelFactory()
{

}

String LabelFactory::getType() const
{
	return String("Label");
}

Window* LabelFactory::createInstance(const String& name)
{
	return new Label(name);
}

void LabelFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
