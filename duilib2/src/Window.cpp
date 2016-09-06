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
	mParent = parent;

	// 更新父窗口的子窗口列表
	std::vector<Window*>& children = parent->getChildren();
	if (std::find(children.begin(), children.end(), this) == children.end())
		children.push_back(this);
}


} // namespace duilib2
