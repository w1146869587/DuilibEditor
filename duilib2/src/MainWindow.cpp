#include <MainWindow.h>

namespace duilib2
{

String MainWindow::sTypeName = "Window";

MainWindow::MainWindow(const String& name)
	: Window(name)
{

}

MainWindow::~MainWindow()
{

}

String MainWindow::getType() const
{
	return sTypeName;
}

} // namespace duilib2
