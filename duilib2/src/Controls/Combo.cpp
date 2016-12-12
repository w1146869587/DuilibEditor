#include <Controls/Combo.h>

namespace duilib2
{

static String gComboProperties[][3] =
{
	// name                   value         type
	{"textpadding",           "0,0,0,0",    "Rect"},
	{"normalimage",           "",           "Image"},
	{"hotimage",              "",           "Image"},
	{"pushedimage",           "",           "Image"},
	{"focusedimage",          "",           "Image"},
	{"disabledimage",         "",           "Image"},
	{"dropboxsize",           "0,150",      "Image"},
	{"itemfont",              "-1",         "Font"},
	{"itemalign",             "center",     "String"},
	{"itemendellipsis",       "false",      "Bool"},
	{"itemtextpadding",       "0,0,0,0",    "Rect"},
	{"itemtextcolor",         "0xFF000000", "Color"},
	{"itembkcolor",           "0x00000000", "Color"},
	{"itembkimage",           "",           "Image"},
	{"itemaltbk",             "false",      "Bool"},
	{"itemselectedtextcolor", "0xFF000000", "Color"},
	{"itemselectedbkcolor",   "0xFFC1E3FF", "Color"},
	{"itemselectedimage",     "",           "Image"},
	{"itemhottextcolor",      "0xFF000000", "Color"},
	{"itemhotbkcolor",        "0xFFE9F5FF", "Color"},
	{"itemhotimage",          "",           "Image"},
	{"itemdisabledtextcolor", "0xFFCCCCCC", "Color"},
	{"itemdisabledbkcolor",   "0xFFFFFFFF", "Color"},
	{"itemdisabledimage",     "",           "Image"},
	{"itemlinecolor",         "0x00000000", "Color"},
	{"itemshowhtml",          "false",      "Bool"},
	{"multiexpanding",        "false",      "Bool"},
	{"", "", ""}
};


String Combo::sTypeName = "Combo";

Combo::Combo(const String& name)
	: Container(name)
{
	String* property = &gComboProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

Combo::~Combo()
{

}

String Combo::getType() const
{
	return sTypeName;
}

int Combo::getWidth() const
{
	return 0;
}

int Combo::getHeight() const
{
	return 0;
}

Point Combo::getPosition() const
{
	return Point();
}


ComboFactory::ComboFactory()
{

}

ComboFactory::~ComboFactory()
{

}

String ComboFactory::getType() const
{
	return String("Combo");
}

Window* ComboFactory::createInstance(const String& name)
{
	return new Combo(name);
}

void ComboFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
