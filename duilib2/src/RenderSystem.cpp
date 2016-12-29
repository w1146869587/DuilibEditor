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

}

void RenderSystem::drawChord(const Rect& rectangle, int startAngle, int spanAngle)
{

}

void RenderSystem::drawEllipse(const Rect& rectangle)
{

}

void RenderSystem::drawImage(const Rect& rectangle, const Image& image, const Rect& source)
{

}

void RenderSystem::drawImage(const Point& point, const Image& image, const Rect& source)
{

}

void RenderSystem::drawImage(const Rect& rectangle, const Image& image)
{

}

void RenderSystem::drawImage(const Point& point, const Image& image)
{

}

void RenderSystem::drawLine(const Point& pt1, const Point& pt2)
{

}

void RenderSystem::drawPie(const Rect& rectangle, int startAngle, int spanAngle)
{

}

void RenderSystem::drawPoint(const Point& position)
{

}

void RenderSystem::drawPolygon(const std::vector<Point>& points)
{

}

void RenderSystem::drawPolyline(const std::vector<Point>& points)
{

}

void RenderSystem::drawRect(const Rect& rectangle)
{

}

void RenderSystem::drawRoundedRect(const Rect& rect, int xRadius, int yRadius)
{

}

void RenderSystem::drawText(const Rect& rectangle, const String& text)
{

}

void RenderSystem::fillRect(int x, int y, int width, int height, const Color& color)
{

}

void RenderSystem::setPenColor(const Color& color)
{
	mRenderSystemImpl->setPenColor(color);
}

Color RenderSystem::getPenColor() const
{
	mRenderSystemImpl->getPenColor();
}

void RenderSystem::setBrushColor(const Color& color)
{
	mRenderSystemImpl->setBrushColor(color);
}

Color RenderSystem::getBrushColor() const
{
	mRenderSystemImpl->getBrushColor();
}

void RenderSystem::setRenderTarget(RenderTarget* renderTarget)
{
	mRenderSystemImpl->setRenderTarget(renderTarget);
}

RenderTarget* RenderSystem::getRenderTarget()
{
	mRenderSystemImpl->getRenderTarget();
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
	mRenderSystemImpl->getClipRegion();
}

bool RenderSystem::hasClipRegion() const
{
	mRenderSystemImpl->hasClipRegion();
}

} // namespace duilib2
