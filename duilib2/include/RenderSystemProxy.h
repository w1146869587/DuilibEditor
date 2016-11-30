#ifndef RENDERSYSTEMPROXY_H
#define RENDERSYSTEMPROXY_H

#include <duilib2_global.h>
#include <RenderTarget.h>
#include <RenderSystem.h>

namespace duilib2
{

class RenderSystemProxy : public RenderSystem
{
public:
	RenderSystemProxy(RenderTarget* rt);
	virtual ~RenderSystemProxy();

	/// @copydoc RenderSystem::reset
	virtual void reset();

	/// @copydoc RenderSystem::drawArc
	virtual void drawArc(const Rect& rectangle, int startAngle, int spanAngle);

	/// @copydoc RenderSystem::drawChord
	virtual void drawChord(const Rect& rectangle, int startAngle, int spanAngle);

	/// @copydoc RenderSystem::drawEllipse
	virtual void drawEllipse(const Rect& rectangle);

	/// @copydoc RenderSystem::drawImage
	virtual void drawImage(const Rect& rectangle, const Image& image, const Rect& source);

	/// @copydoc RenderSystem::drawImage
	virtual void drawImage(const Point& point, const Image& image, const Rect& source);

	/// @copydoc RenderSystem::drawImage
	virtual void drawImage(const Rect& rectangle, const Image& image);

	/// @copydoc RenderSystem::drawImage
	virtual void drawImage(const Point& point, const Image& image);

	/// @copydoc RenderSystem::drawLine
	virtual void drawLine(const Point& pt1, const Point& pt2);

	/// @copydoc RenderSystem::drawPie
	virtual void drawPie(const Rect& rectangle, int startAngle, int spanAngle);

	/// @copydoc RenderSystem::drawPoint
	virtual void drawPoint(const Point& position);

	/// @copydoc RenderSystem::drawPolygon
	virtual void drawPolygon(const std::vector<Point>& points);

	/// @copydoc RenderSystem::drawPolyline
	virtual void drawPolyline(const std::vector<Point>& points);

	/// @copydoc RenderSystem::drawRect
	virtual void drawRect(const Rect& rectangle);

	/// @copydoc RenderSystem::drawRoundedRect
	virtual void drawRoundedRect(const Rect& rect, int xRadius, int yRadius);

	/// @copydoc RenderSystem::drawText
	virtual void drawText(const Rect& rectangle, const String& text);

	/// @copydoc RenderSystem::fillRect
	virtual void fillRect(int x, int y, int width, int height, const Color& color);

	/// @copydoc RenderSystem::setPenColor
	virtual void setPenColor(const Color& color);

	/// @copydoc RenderSystem::getPenColor
	virtual Color getPenColor() const;

	/// @copydoc RenderSystem::setBrushColor
	virtual void setBrushColor(const Color& color);

	/// @copydoc RenderSystem::getBrushColor
	virtual Color getBrushColor() const;

	/// @copydoc RenderSystem::setRenderTarget
	virtual void setRenderTarget(RenderTarget* renderTarget);

	/// @copydoc RenderSystem::getRenderTarget
	virtual RenderTarget* getRenderTarget();

	/// @copydoc RenderSystem::clearClipRegion
	virtual void clearClipRegion();

	/// @copydoc RenderSystem::setClipRegion
	virtual void setClipRegion(const RoundRect& clipRegion);

	/// @copydoc RenderSystem::getClipRegion
	virtual RoundRect getClipRegion() const;

	/// @copydoc RenderSystem::hasClipRegion
	virtual bool hasClipRegion() const;

private:
	RenderSystem* mRenderSystem;
};

} // namespace duilib2

#endif // RENDERSYSTEMPROXY_H
