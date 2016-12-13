#include <Controls/TreeView.h>

namespace duilib2
{

static String gTreeViewProperties[][3] =
{
	// name                 value         type
	{"multipleitem",        "true",       "Bool"},
	{"itemcheckimgsize",    "0,0",        "Size"},
	{"itemiconimgsize",     "0,0",        "Size"},
	{"visiblefolderbtn",    "true",       "Bool"},
	{"visiblecheckbtn",     "false",      "Bool"},
	{"itemminwidth",        "0",          "Int"},
	{"itemtextcolor",       "0x00000000", "Color"},
	{"itemhottextcolor",    "0x00000000", "Color"},
	{"selitemtextcolor",    "0x00000000", "Color"},
	{"selitemhottextcolor", "0x00000000", "Color"},
	{"", "", ""}
};


String TreeView::sTypeName = "TreeView";

TreeView::TreeView(const String& name)
	: List(name)
{
	String* property = &gTreeViewProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

TreeView::~TreeView()
{

}

String TreeView::getType() const
{
	return sTypeName;
}

int TreeView::getWidth() const
{
	return 0;
}

int TreeView::getHeight() const
{
	return 0;
}

Point TreeView::getPosition() const
{
	return Point();
}


TreeViewFactory::TreeViewFactory()
{

}

TreeViewFactory::~TreeViewFactory()
{

}

String TreeViewFactory::getType() const
{
	return String("TreeView");
}

Window* TreeViewFactory::createInstance(const String& name)
{
	return new TreeView(name);
}

void TreeViewFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
