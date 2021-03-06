#include <Controls/ListHeaderItem.h>

namespace duilib2
{

static String gListHeaderItemProperties[][3] =
{
	// name          value          type
	{"dragable",     "true",        "Bool"},
	{"sepwidth",     "4",           "Int"},
	{"align",        "left",        "String"},
	{"endellipsis",  "false",       "Bool"},
	{"font",         "-1",          "Font"},
	{"textcolor",    "0x00000000",  "Color"},
	{"textpadding",  "2,0,2,0",     "Rect"},
	{"showhtml",     "false",       "Bool"},
	{"normalimage",  "",            "Image"},
	{"hotimage",     "",            "Image"},
	{"pushedimage",  "",            "Image"},
	{"focusedimage", "",            "Image"},
	{"sepimage",     "",            "Image"},
	{"", "", ""}
};


String ListHeaderItem::sTypeName = "ListHeaderItem";

ListHeaderItem::ListHeaderItem(const String& name)
	: Control(name)
{
	String* property = &gListHeaderItemProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

ListHeaderItem::~ListHeaderItem()
{

}

String ListHeaderItem::getType() const
{
	return sTypeName;
}

int ListHeaderItem::getWidth() const
{
	return 0;
}

int ListHeaderItem::getHeight() const
{
	return 0;
}

Point ListHeaderItem::getPosition() const
{
	return Point();
}


ListHeaderItemFactory::ListHeaderItemFactory()
{

}

ListHeaderItemFactory::~ListHeaderItemFactory()
{

}

String ListHeaderItemFactory::getType() const
{
	return String("ListHeaderItem");
}

Window* ListHeaderItemFactory::createInstance(const String& name)
{
	return new ListHeaderItem(name);
}

void ListHeaderItemFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
