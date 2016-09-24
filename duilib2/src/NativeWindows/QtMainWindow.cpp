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
	Size size = getProperty("size").getAnyValue<Size>();
	resize(size.mWidth, size.mHeight);

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
		// setClipRegion(0, 0, width(), height(), roundCorner.mWidth, roundCorner.mHeight);

	}

	// ...

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
