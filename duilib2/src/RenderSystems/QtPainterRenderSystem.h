#ifndef QTPAINTERRENDERSYSTEM_H
#define QTPAINTERRENDERSYSTEM_H

#include <RenderSystem.h>
#include <QPainter>

namespace duilib2
{

class QtPainterRenderSystem : public RenderSystem
{
public:
	QtPainterRenderSystem();
	virtual ~QtPainterRenderSystem();

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

private:
	QPaintDevice* getPaintDevice();
	void setupClipRegion(QPainter& painter);
	void initPainter(QPainter& painter);
};

} // namespace duilib2

#endif // QTRENDERSYSTEM_H
