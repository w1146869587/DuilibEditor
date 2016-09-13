#include <MainWindow.h>

namespace duilib2
{

String MainWindow::sTypeName = "Window";

MainWindow::MainWindow(const String& name)
	: Window(name)
{
	// 默认属性
	addProperty("size",               "0, 0",       "Size");
	addProperty("mininfo",            "0, 0",       "Size");
	addProperty("maxinfo",            "0, 0",       "Size");
	addProperty("roundcorner",        "0, 0",       "Size");
	addProperty("sizebox",            "0, 0, 0, 0", "Rect");
	addProperty("caption",            "0, 0, 0, 0", "Rect");
	addProperty("alpha",              "255",        "Byte");
	addProperty("bktrans",            "false",      "Bool");
	addProperty("showdirty",          "false",      "Bool");
	addProperty("disabledfontcolor",  "0xFFA7A6AA", "Color");
	addProperty("defaultfontcolor",   "0xFF000000", "Color");
	addProperty("linkfontcolor",      "0xFF0000FF", "Color");
	addProperty("linkhoverfontcolor", "0xFFD3215F", "Color");
	addProperty("selectedcolor",      "0xFFBAE4FF", "Color");
}

MainWindow::~MainWindow()
{

}

String MainWindow::getType() const
{
	return sTypeName;
}

} // namespace duilib2
