#include <RenderSystems/QtPainterRenderSystem.h>
#include <RenderTargets/QtPaintDeviceRenderTarget.h>
#include <Exception.h>
#include <QPainter>

namespace duilib2
{

QtPainterRenderSystem::QtPainterRenderSystem()
{

}

QtPainterRenderSystem::~QtPainterRenderSystem()
{

}

void QtPainterRenderSystem::fillRect(int x, int y, int width, int height, const Color& color)
{
	QtPaintDeviceRenderTarget* rt = dynamic_cast<QtPaintDeviceRenderTarget*>(getRenderTarget());
	if (rt == NULL)
	{
		DUILIB2_EXCEPT(Exception::ERR_INTERNAL_ERROR,
					   "The render target is not the expected type, "
					   "the expected type is QtPaintDeviceRenderTarget",
					   "QtPainterRenderSystem::fillRect");
	}

	QPaintDevice* paintDevice = rt->getPaintDevice();
	QPainter painter(paintDevice);

	// 设置剪裁区域
	if (hasClipRegion())
	{
		RoundRect region = getClipRegion();

		QPainterPath clipPath;
		clipPath.addRoundedRect(region.mX, region.mY, region.mWidth, region.mHeight,
								region.mXRadius, region.mYRadius);
		painter.setClipPath(clipPath);
	}

	QColor qcolor(color.mRed, color.mGreen, color.mBlue, color.mAlpha);
	painter.fillRect(x, y, width, height, QBrush(qcolor));
}

} // namespace duilib2
