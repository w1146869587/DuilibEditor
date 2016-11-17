#include <RenderSystems/QtPainterRenderSystem.h>
#include <RenderTargets/QtPaintDeviceRenderTarget.h>
#include <Exception.h>

namespace duilib2
{

QtPainterRenderSystem::QtPainterRenderSystem()
{

}

QtPainterRenderSystem::~QtPainterRenderSystem()
{

}

void QtPainterRenderSystem::drawArc(const Rect& rectangle, int startAngle, int spanAngle)
{
	QPainter painter(getPaintDevice());
	setupClipRegion(painter);

	painter.drawArc(QRectF(rectangle.mLeft, rectangle.mTop, rectangle.getWidth(), rectangle.getHeight()),
					startAngle * 16, spanAngle * 16);
}

void QtPainterRenderSystem::drawChord(const Rect& rectangle, int startAngle, int spanAngle)
{
	QPainter painter(getPaintDevice());
	setupClipRegion(painter);

	painter.drawChord(QRectF(rectangle.mLeft, rectangle.mTop, rectangle.getWidth(), rectangle.getHeight()),
					  startAngle * 16, spanAngle * 16);
}

void QtPainterRenderSystem::drawEllipse(const Rect& rectangle)
{
	QPainter painter(getPaintDevice());
	setupClipRegion(painter);

	painter.drawEllipse(QRectF(rectangle.mLeft, rectangle.mTop, rectangle.getWidth(), rectangle.getHeight()));
}

void QtPainterRenderSystem::drawImage(const Rect& rectangle, const Image& image, const Rect& source)
{

}

void QtPainterRenderSystem::drawImage(const Point& point, const Image& image, const Rect& source)
{

}

void QtPainterRenderSystem::drawImage(const Rect& rectangle, const Image& image)
{

}

void QtPainterRenderSystem::drawImage(const Point& point, const Image& image)
{

}

void QtPainterRenderSystem::drawLine(const Point& pt1, const Point& pt2)
{
	QPainter painter(getPaintDevice());
	setupClipRegion(painter);

	painter.drawLine(pt1.mX, pt1.mY, pt2.mX, pt2.mY);
}

void QtPainterRenderSystem::drawPie(const Rect& rectangle, int startAngle, int spanAngle)
{
	QPainter painter(getPaintDevice());
	setupClipRegion(painter);

	painter.drawPie(QRectF(rectangle.mLeft, rectangle.mTop, rectangle.getWidth(), rectangle.getHeight()),
					startAngle * 16, spanAngle * 16);
}

void QtPainterRenderSystem::drawPoint(const Point& position)
{
	QPainter painter(getPaintDevice());
	setupClipRegion(painter);

	painter.drawPoint(position.mX, position.mY);
}

void QtPainterRenderSystem::drawPolygon(const std::vector<Point>& points)
{

}

void QtPainterRenderSystem::drawPolyline(const std::vector<Point>& points)
{

}

void QtPainterRenderSystem::drawRect(const Rect& rectangle)
{
	QPainter painter(getPaintDevice());
	setupClipRegion(painter);

	painter.drawRect(QRectF(rectangle.mLeft, rectangle.mTop, rectangle.getWidth(), rectangle.getHeight()));
}

void QtPainterRenderSystem::drawRoundedRect(const Rect& rect, int xRadius, int yRadius)
{
	QPainter painter(getPaintDevice());
	setupClipRegion(painter);

	painter.drawRoundedRect(
				QRectF(rectangle.mLeft, rectangle.mTop, rectangle.getWidth(), rectangle.getHeight()),
				xRadius, yRadius);
}

void QtPainterRenderSystem::drawText(const Rect& rectangle, const String& text)
{

}

void QtPainterRenderSystem::fillRect(int x, int y, int width, int height, const Color& color)
{
	QPainter painter(getPaintDevice());
	setupClipRegion(painter);

	QColor qcolor(color.mRed, color.mGreen, color.mBlue, color.mAlpha);
	painter.fillRect(x, y, width, height, QBrush(qcolor));
}

void QtPainterRenderSystem::getPaintDevice()
{
	QtPaintDeviceRenderTarget* rt = dynamic_cast<QtPaintDeviceRenderTarget*>(getRenderTarget());
	if (rt == NULL)
	{
		DUILIB2_EXCEPT(Exception::ERR_INTERNAL_ERROR,
					   "The render target is not the expected type, "
					   "the expected type is QtPaintDeviceRenderTarget",
					   "QtPainterRenderSystem::getPaintDevice");
	}

	return rt->getPaintDevice();
}

void QtPainterRenderSystem::setupClipRegion(QPainter& painter)
{
	// 设置剪裁区域
	if (hasClipRegion())
	{
		RoundRect region = getClipRegion();

		QPainterPath clipPath;
		clipPath.addRoundedRect(region.mX, region.mY, region.mWidth, region.mHeight,
								region.mXRadius, region.mYRadius);
		painter.setClipPath(clipPath);
	}
}

} // namespace duilib2
