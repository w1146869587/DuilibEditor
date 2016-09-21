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

String Window::showModal()
{
	// 控件无法显示自己必须有一个顶层的MainWindow
	// 如果控件没有MainWindow父窗口，需要创建一个，并显示该MainWindow
	// MainWindow需要重写该函数
	// ToDo
	// ...
	return String();
}

void Window::render(RenderTarget* renderTarget)
{
	std::vector<Window*>& children = getChildren();
	for (int i = 0; i < (int)children.size(); ++i)
	{
		children[i]->render(renderTarget);
	}
}


} // namespace duilib2
