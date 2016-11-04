#include <NativeWindows/QtMainWindow.h>
#include <memory>
#include <RenderTargets/QtPaintDeviceRenderTarget.h>
#include <PropertyTypes.h>
#include <QMouseEvent>
#include <QDebug>

namespace duilib2
{

QtMainWindow::QtMainWindow(const String& name)
	: MainWindow(name)
	, mLeftButtonPressed(false)
{
	setRenderTarget(new QtPaintDeviceRenderTarget(this));
}

QtMainWindow::~QtMainWindow()
{

}

void QtMainWindow::paintEvent(QPaintEvent* /*event*/)
{
	MainWindow::render();
}

String QtMainWindow::showModal()
{
	initWindow();
	exec();
	return String();
}

Point QtMainWindow::getPosition() const
{
	return Point(geometry().left(), geometry().top());
}

void QtMainWindow::initWindow()
{
	setAttribute(Qt::WA_TranslucentBackground);

	// 窗口边框
	if (isFrameless())
		setWindowFlags(windowFlags() | Qt::FramelessWindowHint);

	// 窗口初始大小
	resize(getWidth(), getHeight());

	// 窗口位置
	if (userSetPosition())
	{
		Point position = getUserSetPosition();
		QRect clientRect = geometry();
		clientRect.moveTo(position.mX, position.mY);
		setGeometry(clientRect);
	}

	// 圆角矩形窗口
	Size roundCorner = getProperty("roundcorner").getAnyValue<Size>();
	if (roundCorner.mWidth != 0 && roundCorner.mHeight != 0)
	{
		// 设置剪裁区域
		setClipRegion(0, 0, width(), height(), roundCorner.mWidth, roundCorner.mHeight);
	}
	else
		clearClipRegion();

	// 窗口最小大小
	Size minSize = getProperty("mininfo").getAnyValue<Size>();
	if (minSize.mWidth != 0 && minSize.mHeight != 0)
		setMinimumSize(minSize.mWidth, minSize.mHeight);

	// 窗口最大大小
	Size maxSize = getProperty("maxinfo").getAnyValue<Size>();
	if (maxSize.mWidth != 0 && maxSize.mHeight != 0)
		setMaximumSize(maxSize.mWidth, maxSize.mHeight);

	// 允许拖动窗口的区域
	mDragArea = getProperty("caption").getAnyValue<Rect>();
	// caption属性第3个参数是距离右边框的距离
	mDragArea.mRight = getWidth() - mDragArea.mRight;
}

void QtMainWindow::mouseMoveEvent(QMouseEvent* event)
{
	QPoint screenPos = event->screenPos().toPoint();
	MouseEventArgs eventArgs(Point(screenPos.x(), screenPos.y()), MB_NONE_BUTTON);
	onMouseMove(eventArgs);
}

void QtMainWindow::mousePressEvent(QMouseEvent* event)
{
	QPoint qtScreenPos = event->screenPos().toPoint();
	Point screenPos(qtScreenPos.x(), qtScreenPos.y());

	// MouseEventArgs是否还要加MouseButton成员？貌似没有必要

	MouseButton button;
	switch (event->button())
	{
	case Qt::LeftButton:
		button = MB_LEFT_BUTTON;
		onMouseLeftButtonDown(MouseEventArgs(screenPos, button));
		break;

	case Qt::RightButton:
		button = MB_RIGHT_BUTTON;
		onMouseRightButtonDown(MouseEventArgs(screenPos, button));
		break;

	case Qt::MidButton:
		button = MB_MID_BUTTON;
		onMouseMidButtonDown(MouseEventArgs(screenPos, button));
		break;
	}
}

void QtMainWindow::mouseReleaseEvent(QMouseEvent* event)
{
	QPoint qtScreenPos = event->screenPos().toPoint();
	Point screenPos(qtScreenPos.x(), qtScreenPos.y());

	MouseButton button;
	switch (event->button())
	{
	case Qt::LeftButton:
		button = MB_LEFT_BUTTON;
		onMouseLeftButtonUp(MouseEventArgs(screenPos, button));
		break;

	case Qt::RightButton:
		button = MB_RIGHT_BUTTON;
		onMouseRightButtonUp(MouseEventArgs(screenPos, button));
		break;

	case Qt::MidButton:
		button = MB_MID_BUTTON;
		onMouseMidButtonUp(MouseEventArgs(screenPos, button));
		break;
	}
}

void QtMainWindow::mouseDoubleClickEvent(QMouseEvent* event)
{
	QPoint qtScreenPos = event->screenPos().toPoint();
	Point screenPos(qtScreenPos.x(), qtScreenPos.y());

	MouseButton button;
	switch (event->button())
	{
	case Qt::LeftButton:
		button = MB_LEFT_BUTTON;
		onMouseLeftButtonDoubleClick(MouseEventArgs(screenPos, button));
		break;

	case Qt::RightButton:
		button = MB_RIGHT_BUTTON;
		//onMouseRightButtonDoubleClick(MouseEventArgs(screenPos, button));
		break;

	case Qt::MidButton:
		button = MB_MID_BUTTON;
		//onMouseMidButtonDoubleClick(MouseEventArgs(screenPos, button));
		break;
	}
}

bool QtMainWindow::onMouseLeftButtonDown(const MouseEventArgs& eventArgs)
{
	if (MainWindow::onMouseLeftButtonDown(eventArgs))
		return true;

	Point localPoint = screenToLocal(eventArgs.mScreenPos);
	if (mDragArea.contains(localPoint))
	{
		// 获得屏幕坐标下的窗口位置
		Point windowPosInParent(geometry().left(), geometry().top());
		Point windowPosScreen = windowPosInParent;
		if (getParent())
			windowPosScreen = getParent()->localToScreen(windowPosInParent);

		QPoint mousePos(eventArgs.mScreenPos.mX, eventArgs.mScreenPos.mY);
		QPoint windowPos(windowPosScreen.mX, windowPosScreen.mY);
		mPressOffset = windowPos - mousePos;
		mLeftButtonPressed = true;
	}

	return true;
}

bool QtMainWindow::onMouseLeftButtonUp(const MouseEventArgs& eventArgs)
{
	if (MainWindow::onMouseLeftButtonUp(eventArgs))
		return true;

	mLeftButtonPressed = false;
	return true;
}

bool QtMainWindow::onMouseMove(const MouseEventArgs& eventArgs)
{
	if (MainWindow::onMouseMove(eventArgs))
		return true;

	if (mLeftButtonPressed)
	{
		Point pos = eventArgs.mScreenPos;
		QPoint mousePos(pos.mX, pos.mY);
		QPoint windowPos = mousePos + mPressOffset;

		Point windowPosScreen(windowPos.x(), windowPos.y());
		Point windowPosLocal = windowPosScreen;
		if (getParent())
			windowPosLocal = getParent()->screenToLocal(windowPosScreen);

		setGeometry(windowPosLocal.mX, windowPosLocal.mY, geometry().width(), geometry().height());
	}
	return true;
}

QtMainWindowFactory::QtMainWindowFactory()
{

}

QtMainWindowFactory::~QtMainWindowFactory()
{

}

String QtMainWindowFactory::getType() const
{
	return String("Window");
}

Window* QtMainWindowFactory::createInstance(const String& name)
{
	return new QtMainWindow(name);
}

void QtMainWindowFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
