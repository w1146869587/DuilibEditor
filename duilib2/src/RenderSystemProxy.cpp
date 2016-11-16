#include <RenderSystemProxy.h>
#include <System.h>

namespace duilib2
{

RenderSystemProxy::RenderSystemProxy(RenderTarget* rt)
{
	mRenderSystem = System::getSingleton().getRenderSystem();
	// assert(mRenderSystem);
	mRenderSystem->setRenderTarget(rt);
}

RenderSystemProxy::~RenderSystemProxy()
{
	mRenderSystem->reset();
}

void RenderSystemProxy::reset()
{
	mRenderSystem->reset();
}


void RenderSystemProxy::drawArc(const Rect& rectangle, int startAngle, int spanAngle)
{
	mRenderSystem->drawArc(rectangle, startAngle, spanAngle);
}

void RenderSystemProxy::drawChord(const Rect& rectangle, int startAngle, int spanAngle)
{
	mRenderSystem->drawChord(rectangle, startAngle, spanAngle);
}

void RenderSystemProxy::drawEllipse(const Rect& rectangle)
{
	mRenderSystem->drawEllipse(rectangle);
}

void RenderSystemProxy::drawImage(const Rect& rectangle, const Image& image, const Rect& source)
{
	mRenderSystem->drawImage(rectangle, image, source);
}

void RenderSystemProxy::drawImage(const Point& point, const Image& image, const Rect& source)
{
	mRenderSystem->drawImage(point, image, source);
}

void RenderSystemProxy::drawImage(const Rect& rectangle, const Image& image)
{
	mRenderSystem->drawImage(rectangle, image);
}

void RenderSystemProxy::drawImage(const Point& point, const Image& image)
{
	mRenderSystem->drawImage(point, image);
}

void RenderSystemProxy::drawLine(const Point& pt1, const Point& pt2)
{
	mRenderSystem->drawLine(pt1, pt2);
}

void RenderSystemProxy::drawPie(const Rect& rectangle, int startAngle, int spanAngle)
{
	mRenderSystem->drawPie(rectangle, startAngle, spanAngle);
}

void RenderSystemProxy::drawPoint(const Point& position)
{
	mRenderSystem->drawPoint(position);
}

void RenderSystemProxy::drawPolygon(const std::vector<Point>& points)
{
	mRenderSystem->drawPolygon(points);
}

void RenderSystemProxy::drawPolyline(const std::vector<Point>& points)
{
	mRenderSystem->drawPolyline(points);
}

void RenderSystemProxy::drawRect(const Rect& rectangle)
{
	mRenderSystem->drawRect(rectangle);
}

void RenderSystemProxy::drawRoundedRect(const Rect& rect, int xRadius, int yRadius)
{
	mRenderSystem->drawRoundedRect(rect, xRadius, yRadius);
}

void RenderSystemProxy::drawText(const Rect& rectangle, const String& text)
{
	mRenderSystem->drawText(rectangle, text);
}

void RenderSystemProxy::fillRect(
		int x, int y, int width, int height, const Color& color)
{
	mRenderSystem->fillRect(x, y, width, height, color);
}

void RenderSystemProxy::setRenderTarget(RenderTarget* renderTarget)
{
	mRenderSystem->setRenderTarget(renderTarget);
}

RenderTarget* RenderSystemProxy::getRenderTarget()
{
	return mRenderSystem->getRenderTarget();
}

void RenderSystemProxy::clearClipRegion()
{
	mRenderSystem->clearClipRegion();
}

void RenderSystemProxy::setClipRegion(const RoundRect& clipRegion)
{
	mRenderSystem->setClipRegion(clipRegion);
}

RoundRect RenderSystemProxy::getClipRegion() const
{
	return mRenderSystem->getClipRegion();
}

bool RenderSystemProxy::hasClipRegion() const
{
	return mRenderSystem->hasClipRegion();
}

} // namespace duilib2
