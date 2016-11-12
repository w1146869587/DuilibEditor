#include <Controls/Edit.h>

namespace duilib2
{

static String gEditProperties[][3] =
{
	// name              value      type
	{"readonly",      "false",      "Bool"},
	{"password",      "false",      "Bool"},
	{"maxchar",       "255",        "Int"},
	{"normalimage",   "",           "Image"},
	{"hotimage",      "",           "Image"},
	{"focusedimage",  "",           "Image"},
	{"disabledimage", "",           "Image"},
	{"nativebkcolor", "0x00000000", "Color"},
	{"", "", ""}
};


String Edit::sTypeName = "Edit";

Edit::Edit(const String& name)
	: Label(name)
{
	String* property = &gEditProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

Edit::~Edit()
{

}

String Edit::getType() const
{
	return sTypeName;
}

int Edit::getWidth() const
{
	return 0;
}

int Edit::getHeight() const
{
	return 0;
}

Point Edit::getPosition() const
{
	return Point();
}


EditFactory::EditFactory()
{

}

EditFactory::~EditFactory()
{

}

String EditFactory::getType() const
{
	return String("Edit");
}

Window* EditFactory::createInstance(const String& name)
{
	return new Edit(name);
}

void EditFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
