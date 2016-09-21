#include <NativeWindows/QtMainWindow.h>
#include <memory>
#include <RenderTargets/QtPaintDeviceRenderTarget.h>

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
	exec();
	return String();
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
