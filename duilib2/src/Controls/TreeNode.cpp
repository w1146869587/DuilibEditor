#include <Controls/TreeNode.h>

namespace duilib2
{

static String gTreeNodeProperties[][3] =
{
	// name              value         type
	{"", "", ""}
};


String TreeNode::sTypeName = "TreeNode";

TreeNode::TreeNode(const String& name)
	: ListContainerElement(name)
{
	String* property = &gTreeNodeProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

TreeNode::~TreeNode()
{

}

String TreeNode::getType() const
{
	return sTypeName;
}

int TreeNode::getWidth() const
{
	return 0;
}

int TreeNode::getHeight() const
{
	return 0;
}

Point TreeNode::getPosition() const
{
	return Point();
}

void TreeNode::render()
{

}


TreeNodeFactory::TreeNodeFactory()
{

}

TreeNodeFactory::~TreeNodeFactory()
{

}

String TreeNodeFactory::getType() const
{
	return String("TreeNode");
}

Window* TreeNodeFactory::createInstance(const String& name)
{
	return new TreeNode(name);
}

void TreeNodeFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
