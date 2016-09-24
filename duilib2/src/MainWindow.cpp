#include <MainWindow.h>
#include <PropertyTypes.h>

namespace duilib2
{

String MainWindow::sTypeName = "Window";

MainWindow::MainWindow(const String& name)
	: Window(name)
	, mFrameless(true)
	, mUserSetPosition(false)
	, mPosX(0)
	, mPosY(0)
{
	// 默认属性
	addProperty("size",               "800, 600",   "Size");
	addProperty("mininfo",            "0, 0",       "Size");
	addProperty("maxinfo",            "0, 0",       "Size");
	addProperty("roundcorner",        "0, 0",       "Size");
	addProperty("sizebox",            "8, 8, 8, 8", "Rect");
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

void MainWindow::setFrameless(bool enable)
{
	mFrameless = enable;
}

bool MainWindow::isFrameless() const
{
	return mFrameless;
}

void MainWindow::render(RenderTarget* renderTarget)
{
	//RenderSystem* rs = ...;

	// 是否使用静态透明背景
	// 如果不使用，则绘制一个纯色背景
	Bool bktrans = getProperty("bktrans").getAnyValue<Bool>();
	if (!bktrans)
	{
		//if (mClippling)
		//	rs.setClipRegion(mClipRegion);

		//rs.fillRect(...);
	}

	Window::render(renderTarget);
}

void MainWindow::setPosition(int x, int y)
{
	mPosX = x;
	mPosY = y;
	mUserSetPosition = true;
}

std::pair<int, int> MainWindow::getPosition() const
{
	return std::make_pair(mPosX, mPosY);
}

bool MainWindow::userSetPosition() const
{
	return mUserSetPosition;
}

} // namespace duilib2
