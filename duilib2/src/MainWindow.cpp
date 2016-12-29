#include <MainWindow.h>
#include <PropertyTypes.h>
#include <RenderSystemImpl.h>

namespace duilib2
{

static String gMainWindowProperties[][3] =
{
	// default properties
	// name               value         type
	{"size",               "800, 600",   "Size"},
	{"mininfo",            "0, 0",       "Size"},
	{"maxinfo",            "0, 0",       "Size"},
	{"roundcorner",        "0, 0",       "Size"},
	{"sizebox",            "8, 8, 8, 8", "Rect"},
	{"caption",            "0, 0, 0, 0", "Rect"},
	{"alpha",              "255",        "Byte"},
	{"bktrans",            "false",      "Bool"},
	{"showdirty",          "false",      "Bool"},
	{"disabledfontcolor",  "0xFFA7A6AA", "Color"},
	{"defaultfontcolor",   "0xFF000000", "Color"},
	{"linkfontcolor",      "0xFF0000FF", "Color"},
	{"linkhoverfontcolor", "0xFFD3215F", "Color"},
	{"selectedcolor",      "0xFFBAE4FF", "Color"},
	{"", "", ""}
};

String MainWindow::sTypeName = "Window";

MainWindow::MainWindow(const String& name)
	: Window(name)
	, mFrameless(true)
	, mUserSetPosition(false)
	, mPosX(0)
	, mPosY(0)
{
	String* property = &gMainWindowProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

MainWindow::~MainWindow()
{

}

String MainWindow::getType() const
{
	return sTypeName;
}

int MainWindow::getWidth() const
{
	Size size = getProperty("size").getAnyValue<Size>();
	return size.mWidth;
}

int MainWindow::getHeight() const
{
	Size size = getProperty("size").getAnyValue<Size>();
	return size.mHeight;
}

void MainWindow::setFrameless(bool enable)
{
	mFrameless = enable;
}

bool MainWindow::isFrameless() const
{
	return mFrameless;
}

void MainWindow::render()
{
	RenderTarget* rt = getRenderTarget();
	if (rt == NULL)
		return;

	RenderSystemProxy rs(rt);

	// 是否使用静态透明背景
	// 如果不使用，则绘制一个纯色背景
	Bool bktrans = getProperty("bktrans").getAnyValue<Bool>();
	if (!bktrans)
	{
		if (mClipping)
			rs.setClipRegion(mClipRegion);
		else
			rs.clearClipRegion();

		Byte alpha = getProperty("alpha").getAnyValue<Byte>();
		rs.fillRect(0, 0, getWidth(), getHeight(), Color(128, 128, 128, alpha));
	}

	Window::render();
}

void MainWindow::setPosition(int x, int y)
{
	mPosX = x;
	mPosY = y;
	mUserSetPosition = true;
}

Point MainWindow::getUserSetPosition() const
{
	return Point(mPosX, mPosY);
}

void MainWindow::setClipRegion(int x, int y, int width, int height, int xRadius, int yRadius)
{
	mClipping = true;
	mClipRegion = RoundRect(x, y, width, height, xRadius, yRadius);
}

void MainWindow::clearClipRegion()
{
	mClipping = false;
}

Window::PropertyMaps MainWindow::_getProperties() const
{
	PropertyMaps propertyMaps = Window::_getProperties();
	PropertyMap  properties;

	String* property = &gMainWindowProperties[0][0];
	while (!property->isEmpty())
	{
		properties[property[0]] = Property(property[0], property[1], property[2]);
		property += 3;
	}
	propertyMaps.push_back(std::make_pair(String("Window"), properties));
	return propertyMaps;
}

bool MainWindow::userSetPosition() const
{
	return mUserSetPosition;
}

} // namespace duilib2
