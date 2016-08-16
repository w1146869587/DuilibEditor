#include "mainwindow.h"
#include <QApplication>

#include <duilib2.h>
using namespace duilib2;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	System::create();

	// 资源
	ResourceManager::getSingleton().addResource("default", "zip", "default.zip");
	ResourceManager::getSingleton().setCurrentResource("default");

	// 加载布局
	Window* rootWindow = WindowManager::getSingleton().loadLayoutFromFile("main.xml");
	//rootWindow->showModal();

	System::destroy();

	return a.exec();
}
