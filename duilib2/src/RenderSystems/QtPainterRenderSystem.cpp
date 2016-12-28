#include <Exception.h>
#include "QtPainterRenderSystem.h"
#include "../RenderTargets/QtPaintDeviceRenderTarget.h"

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
	initPainter(painter);
	setupClipRegion(painter);

	painter.drawArc(QRectF(rectangle.mLeft, rectangle.mTop, rectangle.getWidth(), rectangle.getHeight()),
					startAngle * 16, spanAngle * 16);
}

void QtPainterRenderSystem::drawChord(const Rect& rectangle, int startAngle, int spanAngle)
{
	QPainter painter(getPaintDevice());
	initPainter(painter);
	setupClipRegion(painter);

	painter.drawChord(QRectF(rectangle.mLeft, rectangle.mTop, rectangle.getWidth(), rectangle.getHeight()),
					  startAngle * 16, spanAngle * 16);
}

void QtPainterRenderSystem::drawEllipse(const Rect& rectangle)
{
	QPainter painter(getPaintDevice());
	initPainter(painter);
	setupClipRegion(painter);

	painter.drawEllipse(QRectF(rectangle.mLeft, rectangle.mTop, rectangle.getWidth(), rectangle.getHeight()));
}

void QtPainterRenderSystem::drawImage(const Rect& rectangle, const QImage& image, const Rect& source)
{
	QPainter painter(getPaintDevice());
	initPainter(painter);
	setupClipRegion(painter);

	painter.drawImage(QRectF(rectangle.mLeft, rectangle.mTop, rectangle.getWidth(), rectangle.getHeight()),
					  image, QRectF(source.mLeft, source.mTop, source.getWidth(), source.getHeight()));
}

void QtPainterRenderSystem::drawImage(const Point& point, const QImage& image, const Rect& source)
{
	QPainter painter(getPaintDevice());
	initPainter(painter);
	setupClipRegion(painter);

	painter.drawImage(QRectF(point.mX, point.mY, source.getWidth(), source.getHeight()),
					  image, QRectF(source.mLeft, source.mTop, source.getWidth(), source.getHeight()));
}

void QtPainterRenderSystem::drawImage(const Rect& rectangle, const QImage& image)
{
	QPainter painter(getPaintDevice());
	initPainter(painter);
	setupClipRegion(painter);

	painter.drawImage(QRectF(rectangle.mLeft, rectangle.mTop, rectangle.getWidth(), rectangle.getHeight()),
					  image);
}

void QtPainterRenderSystem::drawImage(const Point& point, const QImage& image)
{
	QPainter painter(getPaintDevice());
	initPainter(painter);
	setupClipRegion(painter);

	painter.drawImage(QRectF(point.mX, point.mY, image.width(), image.height()), image);
}

void QtPainterRenderSystem::drawLine(const Point& pt1, const Point& pt2)
{
	QPainter painter(getPaintDevice());
	initPainter(painter);
	setupClipRegion(painter);

	painter.drawLine(pt1.mX, pt1.mY, pt2.mX, pt2.mY);
}

void QtPainterRenderSystem::drawPie(const Rect& rectangle, int startAngle, int spanAngle)
{
	QPainter painter(getPaintDevice());
	initPainter(painter);
	setupClipRegion(painter);

	painter.drawPie(QRectF(rectangle.mLeft, rectangle.mTop, rectangle.getWidth(), rectangle.getHeight()),
					startAngle * 16, spanAngle * 16);
}

void QtPainterRenderSystem::drawPoint(const Point& position)
{
	QPainter painter(getPaintDevice());
	initPainter(painter);
	setupClipRegion(painter);

	painter.drawPoint(position.mX, position.mY);
}

void QtPainterRenderSystem::drawPolygon(const std::vector<Point>& points)
{
	QPainter painter(getPaintDevice());
	initPainter(painter);
	setupClipRegion(painter);

	QPoint* qpoints = new QPoint[points.size()];
	for (int i = 0; i < (int)points.size(); ++i)
		qpoints[i] = QPoint(points[i].mX, points[i].mY);

	painter.drawPolygon(qpoints, (int)points.size());
	delete[] qpoints;
}

void QtPainterRenderSystem::drawPolyline(const std::vector<Point>& points)
{
	QPainter painter(getPaintDevice());
	initPainter(painter);
	setupClipRegion(painter);

	QPoint* qpoints = new QPoint[points.size()];
	for (int i = 0; i < (int)points.size(); ++i)
		qpoints[i] = QPoint(points[i].mX, points[i].mY);

	painter.drawPolyline(qpoints, (int)points.size());
	delete[] qpoints;
}

void QtPainterRenderSystem::drawRect(const Rect& rectangle)
{
	QPainter painter(getPaintDevice());
	initPainter(painter);
	setupClipRegion(painter);

	painter.drawRect(QRectF(rectangle.mLeft, rectangle.mTop, rectangle.getWidth(), rectangle.getHeight()));
}

void QtPainterRenderSystem::drawRoundedRect(const Rect& rect, int xRadius, int yRadius)
{
	QPainter painter(getPaintDevice());
	initPainter(painter);
	setupClipRegion(painter);

	painter.drawRoundedRect(
				QRectF(rect.mLeft, rect.mTop, rect.getWidth(), rect.getHeight()),
				xRadius, yRadius);
}

void QtPainterRenderSystem::drawText(const Rect& rectangle, const String& text)
{
	QPainter painter(getPaintDevice());
	initPainter(painter);
	setupClipRegion(painter);

	painter.drawText(QRectF(rectangle.mLeft, rectangle.mTop, rectangle.getWidth(), rectangle.getHeight()),
					 text);
}

void QtPainterRenderSystem::fillRect(int x, int y, int width, int height, const Color& color)
{
	QPainter painter(getPaintDevice());
	initPainter(painter);
	setupClipRegion(painter);

	QColor qcolor(color.mRed, color.mGreen, color.mBlue, color.mAlpha);
	painter.fillRect(x, y, width, height, QBrush(qcolor));
}

QPaintDevice* QtPainterRenderSystem::getPaintDevice()
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

void QtPainterRenderSystem::initPainter(QPainter& painter)
{
	Color penColor = getPenColor();
	Color brushColor = getBrushColor();
	painter.setPen(QColor(penColor.mRed, penColor.mGreen, penColor.mBlue, penColor.mAlpha));
	painter.setBrush(QBrush(QColor(brushColor.mRed, brushColor.mGreen, brushColor.mBlue, brushColor.mAlpha)));
}

} // namespace duilib2
