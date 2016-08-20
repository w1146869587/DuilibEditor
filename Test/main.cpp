#include "mainwindow.h"
#include <QApplication>

#include <duilib2.h>
using namespace duilib2;

#include <QFile>
#include <XmlParsers/QtXmlParser.h>
#include <iostream>
#include <QTextStream>

void testQtXmlParser();

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	testQtXmlParser();

	System::create();

	// 资源
	ResourceManager::getSingleton().addResourcePackage("default", "zip", "default.zip");
	ResourceManager::getSingleton().setCurrentResourcePackage("default");

	// 加载布局
	Window* rootWindow = WindowManager::getSingleton().loadLayoutFromFile("main.xml");
	//rootWindow->showModal();

	System::destroy();

	return a.exec();
}


class TestXmlHandler : public XmlHandler
{
public:
	virtual void elementStart(const String& element, const XmlAttributes& attributes)
	{
		std::cout << element.toLocal8Bit().data() << std::endl;

		int attrCount = attributes.getCount();
		for (int i=0; i<attrCount; ++i)
		{
			std::cout << "    " << attributes.getName(i).toLocal8Bit().data() << " : "
					  << attributes.getValue(i).toLocal8Bit().data() << std::endl;
		}
	}
};

void testQtXmlParser()
{
	QFile file("test.xml");
	file.open(QIODevice::ReadOnly | QIODevice::Text);

	QString fileData = QString::fromUtf8(file.readAll());

	TestXmlHandler handler;
	QtXmlParser parser;
	parser.parseXmlString(handler, fileData);
	file.close();
}
