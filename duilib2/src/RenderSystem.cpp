#include <RenderSystem.h>
#include "RenderSystems/QtPainterRenderSystem.h"

namespace duilib2
{

RenderSystem::RenderSystem(RenderTarget* rt)
{
	// TODO, separate to another file
	mRenderSystemImpl = new QtPainterRenderSystem(rt);
}

RenderSystem::~RenderSystem()
{
	delete mRenderSystemImpl;
}

void RenderSystem::drawArc(const Rect& rectangle, int startAngle, int spanAngle)
{
	mRenderSystemImpl->drawArc(rectangle, startAngle, spanAngle);
}

void RenderSystem::drawChord(const Rect& rectangle, int startAngle, int spanAngle)
{
	mRenderSystemImpl->drawChord(rectangle, startAngle, spanAngle);
}

void RenderSystem::drawEllipse(const Rect& rectangle)
{
	mRenderSystemImpl->drawEllipse(rectangle);
}

void RenderSystem::drawImage(const Rect& rectangle, const Image& image, const Rect& source)
{
	mRenderSystemImpl->drawImage(rectangle, image, source);
}

void RenderSystem::drawImage(const Point& point, const Image& image, const Rect& source)
{
	mRenderSystemImpl->drawImage(point, image, source);
}

void RenderSystem::drawImage(const Rect& rectangle, const Image& image)
{
	mRenderSystemImpl->drawImage(rectangle, image);
}

void RenderSystem::drawImage(const Point& point, const Image& image)
{
	mRenderSystemImpl->drawImage(point, image);
}

void RenderSystem::drawLine(const Point& pt1, const Point& pt2)
{
	mRenderSystemImpl->drawLine(pt1, pt2);
}

void RenderSystem::drawPie(const Rect& rectangle, int startAngle, int spanAngle)
{
	mRenderSystemImpl->drawPie(rectangle, startAngle, spanAngle);
}

void RenderSystem::drawPoint(const Point& position)
{
	mRenderSystemImpl->drawPoint(position);
}

void RenderSystem::drawPolygon(const std::vector<Point>& points)
{
	mRenderSystemImpl->drawPolygon(points);
}

void RenderSystem::drawPolyline(const std::vector<Point>& points)
{
	mRenderSystemImpl->drawPolyline(points);
}

void RenderSystem::drawRect(const Rect& rectangle)
{
	mRenderSystemImpl->drawRect(rectangle);
}

void RenderSystem::drawRoundedRect(const Rect& rect, int xRadius, int yRadius)
{
	mRenderSystemImpl->drawRoundedRect(rect, xRadius, yRadius);
}

void RenderSystem::drawText(const Rect& rectangle, const String& text)
{
	mRenderSystemImpl->drawText(rectangle, text);
}

void RenderSystem::fillRect(int x, int y, int width, int height, const Color& color)
{
	mRenderSystemImpl->fillRect(x, y, width, height, color);
}

void RenderSystem::setPenColor(const Color& color)
{
	mRenderSystemImpl->setPenColor(color);
}

Color RenderSystem::getPenColor() const
{
	return mRenderSystemImpl->getPenColor();
}

void RenderSystem::setBrushColor(const Color& color)
{
	mRenderSystemImpl->setBrushColor(color);
}

Color RenderSystem::getBrushColor() const
{
	return mRenderSystemImpl->getBrushColor();
}

void RenderSystem::setRenderTarget(RenderTarget* renderTarget)
{
	mRenderSystemImpl->setRenderTarget(renderTarget);
}

RenderTarget* RenderSystem::getRenderTarget()
{
	return mRenderSystemImpl->getRenderTarget();
}

void RenderSystem::clearClipRegion()
{
	mRenderSystemImpl->clearClipRegion();
}

void RenderSystem::setClipRegion(const RoundRect& clipRegion)
{
	mRenderSystemImpl->setClipRegion(clipRegion);
}

RoundRect RenderSystem::getClipRegion() const
{
	return mRenderSystemImpl->getClipRegion();
}

bool RenderSystem::hasClipRegion() const
{
	return mRenderSystemImpl->hasClipRegion();
}

} // namespace duilib2
