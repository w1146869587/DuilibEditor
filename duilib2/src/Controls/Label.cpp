#include <Controls/Label.h>

namespace duilib2
{

static String gLabelProperties[][3] =
{
	// name               value             type
	{"endellipsis",       "false",          "Bool"},
	{"font",              "-1",             "Int"},
	{"textcolor",         "0x00000000",     "Color"},
	{"disabledtextcolor", "0x00000000",     "Color"},
	{"textpadding",       "0,0,0,0",        "Rect"},
	{"showhtml",          "false",          "Bool"},
	{"enabledeffect",     "false",          "Bool"},
	{"align",             "left",           "String"},
	{"valign",            "center",         "String"},
	{"rhaa",              "0",              "Int"},
	{"enabledstroke",     "false",          "Bool"},
	{"strokecolor",       "0x00000000",     "Color"},
	{"transstroke",       "255",            "Int"},
	{"enabledshadow",     "false",          "Bool"},
	{"gradientangle",     "0",              "Int"},
	{"gradientlength",    "0",              "Int"},
	{"textcolor1",        "0x00000000",     "Color"},
	{"textshadowcolora",  "0xff000000",     "Color"},
	{"textshadowcolorb",  "0xff000000",     "Color"},
	{"transshadow",       "100",            "Int"},
	{"transshadow1",      "100",            "Int"},
	{"transtext",         "100",            "Int"},
	{"transtext1",        "100",            "Int"},
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
