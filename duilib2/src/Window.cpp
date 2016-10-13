#include "Window.h"
#include <algorithm>

namespace duilib2
{

Window::Window(const String& name)
	: mName(name)
	, mParent(NULL)
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

Window* Window::getParent()
{
	return mParent;
}

const Window* Window::getParent() const
{
	return mParent;
}

Point Window::screenToLocal(const Point& screenPos) const
{
	Point localPos = screenPos;
	localPos.mX -= getPosition().mX;
	localPos.mY -= getPosition().mY;

	const Window* parent = getParent();
	while (parent)
	{
		Point parentPos = parent->getPosition();
		localPos.mX -= parentPos.mX;
		localPos.mY -= parentPos.mY;

		parent = parent->getParent();
	}

	return localPos;
}

Point Window::localToScreen(const Point& localPos) const
{
	Point screenPos = localPos;
	screenPos.mX += getPosition().mX;
	screenPos.mY += getPosition().mY;

	const Window* parent = getParent();
	while (parent)
	{
		Point parentPos = parent->getPosition();
		screenPos.mX += parentPos.mX;
		screenPos.mY += parentPos.mY;

		parent = parent->getParent();
	}

	return screenPos;
}

bool Window::hitTest(const Point& screenPos) const
{
	Point windowPos = getPosition();
	windowPos = localToScreen(windowPos);

	Rect windowArea;
	windowArea.mLeft = windowPos.mX;
	windowArea.mTop = windowPos.mY;
	windowArea.mRight = windowArea.mLeft + getWidth();
	windowArea.mBottom = windowArea.mTop + getHeight();

	return windowArea.contains(screenPos);
}

bool Window::onMouseLeftButtonDown(const MouseEventArgs& eventArgs)
{
	std::vector<Window*>& children = getChildren();
	for (int i = 0; i < (int)children.size(); ++i)
	{
		bool hitTest = children[i]->hitTest(eventArgs.mScreenPos);
		if (hitTest && children[i]->onMouseLeftButtonDown(eventArgs))
			return true;
	}

	return true;
}

bool Window::onMouseLeftButtonUp(const MouseEventArgs& eventArgs)
{
	std::vector<Window*>& children = getChildren();
	for (int i = 0; i < (int)children.size(); ++i)
	{
		bool hitTest = children[i]->hitTest(eventArgs.mScreenPos);
		if (hitTest && children[i]->onMouseLeftButtonUp(eventArgs))
			return true;
	}

	return true;
}

bool Window::onMouseRightButtonDown(const MouseEventArgs& eventArgs)
{
	std::vector<Window*>& children = getChildren();
	for (int i = 0; i < (int)children.size(); ++i)
	{
		bool hitTest = children[i]->hitTest(eventArgs.mScreenPos);
		if (hitTest && children[i]->onMouseRightButtonDown(eventArgs))
			return true;
	}

	return true;
}

bool Window::onMouseRightButtonUp(const MouseEventArgs& eventArgs)
{
	std::vector<Window*>& children = getChildren();
	for (int i = 0; i < (int)children.size(); ++i)
	{
		bool hitTest = children[i]->hitTest(eventArgs.mScreenPos);
		if (hitTest && children[i]->onMouseRightButtonUp(eventArgs))
			return true;
	}

	return true;
}

bool Window::onMouseMidButtonDown(const MouseEventArgs& eventArgs)
{
	std::vector<Window*>& children = getChildren();
	for (int i = 0; i < (int)children.size(); ++i)
	{
		bool hitTest = children[i]->hitTest(eventArgs.mScreenPos);
		if (hitTest && children[i]->onMouseMidButtonDown(eventArgs))
			return true;
	}

	return true;
}

bool Window::onMouseMidButtonUp(const MouseEventArgs& eventArgs)
{
	std::vector<Window*>& children = getChildren();
	for (int i = 0; i < (int)children.size(); ++i)
	{
		bool hitTest = children[i]->hitTest(eventArgs.mScreenPos);
		if (hitTest && children[i]->onMouseMidButtonUp(eventArgs))
			return true;
	}

	return true;
}

bool Window::onMouseLeftButtonDoubleClick(const MouseEventArgs& eventArgs)
{
	std::vector<Window*>& children = getChildren();
	for (int i = 0; i < (int)children.size(); ++i)
	{
		bool hitTest = children[i]->hitTest(eventArgs.mScreenPos);
		if (hitTest && children[i]->onMouseLeftButtonDoubleClick(eventArgs))
			return true;
	}

	return true;
}

bool Window::onMouseMove(const MouseEventArgs& eventArgs)
{
	std::vector<Window*>& children = getChildren();
	for (int i = 0; i < (int)children.size(); ++i)
	{
		bool hitTest = children[i]->hitTest(eventArgs.mScreenPos);
		if (hitTest && children[i]->onMouseMove(eventArgs))
			return true;
	}

	return true;
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

int Window::getWidth() const
{
	return 0;
}

int Window::getHeight() const
{
	return 0;
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
