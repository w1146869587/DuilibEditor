#include <NativeWindows/QtMainWindow.h>

namespace duilib2
{

QtMainWindow::QtMainWindow(const String& name)
	: MainWindow(name)
{

}

QtMainWindow::~QtMainWindow()
{

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
