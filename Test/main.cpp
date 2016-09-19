#include "mainwindow.h"
#include <QApplication>

#include <duilib2.h>
using namespace duilib2;

#include <QFile>
#include <XmlParsers/QtXmlParser.h>
#include <iostream>
#include <QTextStream>
#include <PropertyParsers.h>
#include <PropertyTypes.h>

void testQtXmlParser();
void testPropertyParsers();

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	//testQtXmlParser();
	testPropertyParsers();

	/*
	System::create();

	// 资源
	ResourceManager::getSingleton().addResourcePackage("default", "zip", "default.zip");
	ResourceManager::getSingleton().setCurrentResourcePackage("default");

	// 加载布局
	Window* rootWindow = WindowManager::getSingleton().loadLayoutFromFile("main.xml");
	//rootWindow->showModal();

	System::destroy();
	*/

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
	/*
	QFile file("test.xml");
	file.open(QIODevice::ReadOnly | QIODevice::Text);

	QString fileData = QString::fromUtf8(file.readAll());

	TestXmlHandler handler;
	QtXmlParser parser;
	parser.parseXmlString(handler, fileData);
	file.close();
	*/

	System::create();

	// 资源
	ResourceManager::getSingleton().addResourcePackage("default", "FileSystem", ".");
	ResourceManager::getSingleton().setCurrentResourcePackage("default");

	RawDataContainerPtr rawData = ResourceManager::getSingleton().getFileRawData("test.xml");

	TestXmlHandler handler;
	QtXmlParser parser;
	parser.parseXml(handler, *rawData.get());

	System::destroy();
}

void testPropertyParsers()
{
	// test color
	Property color1("name1", "0xff7bff60", "Color"); // 255, 123, 255, 96

	ColorPropertyParser parser1;
	parser1.parse(color1);
	Color c = color1.getAnyValue<Color>();
	std::cout << c.mAlpha << ' ' << c.mRed << ' ' << c.mGreen << ' ' << c.mBlue << std::endl;
	if (c.mAlpha == 255 && c.mRed == 123 && c.mGreen == 255 && c.mBlue == 96)
		std::cout << "OK!" << std::endl;
	else
		std::cout << "Error!" << std::endl;

	Property color2("name1", "0x7bff60", "Color");
	parser1.parse(color2);
	c = color2.getAnyValue<Color>();
	std::cout << c.mAlpha << ' ' << c.mRed << ' ' << c.mGreen << ' ' << c.mBlue << std::endl;
	if (c.mAlpha == 255 && c.mRed == 123 && c.mGreen == 255 && c.mBlue == 96)
		std::cout << "OK!" << std::endl;
	else
		std::cout << "Error!" << std::endl;

	Property color3("name1", "0xfff60", "Color");    // 15, 123, 255, 96
	parser1.parse(color3);
	c = color3.getAnyValue<Color>();
	std::cout << c.mAlpha << ' ' << c.mRed << ' ' << c.mGreen << ' ' << c.mBlue << std::endl;
	if (c.mAlpha == 255 && c.mRed == 15 && c.mGreen == 255 && c.mBlue == 96)
		std::cout << "OK!" << std::endl;
	else
		std::cout << "Error!" << std::endl;

	Property color4("name1", "7bff60", "Color");
	parser1.parse(color4);
	c = color4.getAnyValue<Color>();
	std::cout << c.mAlpha << ' ' << c.mRed << ' ' << c.mGreen << ' ' << c.mBlue << std::endl;
	if (c.mAlpha == 255 && c.mRed == 123 && c.mGreen == 255 && c.mBlue == 96)
		std::cout << "OK!" << std::endl;
	else
		std::cout << "Error!" << std::endl;

	try
	{
		Property color5("name1", "0xff60", "Color");     // Error
		parser1.parse(color5);
		std::cout << "Error!" << std::endl;
	}
	catch (...)
	{
		std::cout << "Catch Exception, OK!" << std::endl;
	}

}
