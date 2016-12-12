#include <Controls/List.h>

namespace duilib2
{

static String gListProperties[][3] =
{
	// name                   value         type
	{"header",                "true",       "Bool"},
	{"headerbkimage",         "",           "Image"},
	{"scrollselect",          "false",      "Bool"},
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


String List::sTypeName = "List";

List::List(const String& name)
	: VerticalLayout(name)
{
	String* property = &gListProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

List::~List()
{

}

String List::getType() const
{
	return sTypeName;
}

int List::getWidth() const
{
	return 0;
}

int List::getHeight() const
{
	return 0;
}

Point List::getPosition() const
{
	return Point();
}


ListFactory::ListFactory()
{

}

ListFactory::~ListFactory()
{

}

String ListFactory::getType() const
{
	return String("List");
}

Window* ListFactory::createInstance(const String& name)
{
	return new List(name);
}

void ListFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
