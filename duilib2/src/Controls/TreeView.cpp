#include <Controls/TreeView.h>

namespace duilib2
{

static String gTreeViewProperties[][3] =
{
	// name              value         type
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

void TreeView::render()
{

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
