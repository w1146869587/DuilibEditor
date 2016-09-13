#include "Window.h"
#include <algorithm>

namespace duilib2
{

Window::Window(const String& name)
	: mName(name)
{

}

Window::~Window()
{

}

std::vector<Window*>& Window::getChildren()
{
	return mChildren;
}

const std::vector<Window*>& Window::getChildren() const
{
	return mChildren;
}

void Window::setParent(Window* parent)
{
	// 更新父窗口的子窗口列表
	if(parent == NULL)
	{
		std::vector<Window*>& children = mParent->getChildren();
		std::vector<Window*>::iterator pos = std::find(children.begin(), children.end(), this);
		if (pos != children.end())
			children.erase(pos);

	}
	else
	{
		std::vector<Window*>& children = parent->getChildren();
		if (std::find(children.begin(), children.end(), this) == children.end())
			children.push_back(this);
	}

	mParent = parent;
}


} // namespace duilib2
