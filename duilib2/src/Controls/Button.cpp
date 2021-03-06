#include <Controls/Button.h>

namespace duilib2
{

static String gButtonProperties[][3] =
{
	// name               value         type
	{"normalimage",       "",           "Image"},
	{"hotimage",          "",           "Image"},
	{"pushedimage",       "",           "Image"},
	{"focusedimage",      "",           "Image"},
	{"disabledimage",     "",           "Image"},
	{"hottextcolor",      "0x00000000", "Color"},
	{"pushedtextcolor",   "0x00000000", "Color"},
	{"focusedtextcolor",  "0x00000000", "Color"},
	{"", "", ""}
};


String Button::sTypeName = "Button";

Button::Button(const String& name)
	: Label(name)
	, mButtonStatus(BS_NORMAL)
{
	String* property = &gButtonProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

Button::~Button()
{

}

String Button::getType() const
{
	return sTypeName;
}

int Button::getWidth() const
{
	return 0;
}

int Button::getHeight() const
{
	return 0;
}

Point Button::getPosition() const
{
	return Point();
}

void Button::drawStatusImage(RenderSystem* rs)
{

	String propertyName;
	switch (mButtonStatus)
	{
	case BS_NORMAL:
		propertyName = "normalimage";
		break;

	case BS_HOT:
		propertyName = "hotimage";
		break;

	case BS_PUSHED:
		propertyName = "pushedimage";
		break;

	case BS_FOCUSED:
		propertyName = "focusedimage";
		break;

	case BS_DISABLE:
		propertyName = "disabledimage";
		break;

	default:
		return;
	}

	Image image = getProperty(propertyName).getAnyValue<Image>();
	// rs->drawImage(x, y, width, height);
}

void Button::drawText(RenderSystem* rs)
{

}


ButtonFactory::ButtonFactory()
{

}

ButtonFactory::~ButtonFactory()
{

}

String ButtonFactory::getType() const
{
	return String("Button");
}

Window* ButtonFactory::createInstance(const String& name)
{
	return new Button(name);
}

void ButtonFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
