#include <NativeWindows/QtMainWindow.h>
#include <memory>
#include <RenderTargets/QtPaintDeviceRenderTarget.h>
#include <PropertyTypes.h>

namespace duilib2
{

QtMainWindow::QtMainWindow(const String& name)
	: MainWindow(name)
{

}

QtMainWindow::~QtMainWindow()
{

}

void QtMainWindow::paintEvent(QPaintEvent* /*event*/)
{
	std::auto_ptr<RenderTarget> renderTarget(new QtPaintDeviceRenderTarget(this));
	MainWindow::render(renderTarget.get());
}

String QtMainWindow::showModal()
{
	initWindow();
	exec();
	return String();
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
		std::pair<int, int> position = getPosition();
		QRect clientRect = geometry();
		clientRect.moveTo(position.first, position.second);
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
