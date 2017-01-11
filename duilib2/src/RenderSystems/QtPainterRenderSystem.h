#ifndef QTPAINTERRENDERSYSTEM_H
#define QTPAINTERRENDERSYSTEM_H

#include <RenderSystemImpl.h>
#include <QPainter>

namespace duilib2
{

class QtPainterRenderSystem : public RenderSystemImpl
{
public:
	QtPainterRenderSystem(RenderTarget* rt);
	virtual ~QtPainterRenderSystem();

	virtual void drawArc(const Rect& rectangle, int startAngle, int spanAngle);

	virtual void drawChord(const Rect& rectangle, int startAngle, int spanAngle);

	virtual void drawEllipse(const Rect& rectangle);

	virtual void drawImage(const Rect& rectangle, const Image& image, const Rect& source);

	virtual void drawImage(const Point& point, const Image& image, const Rect& source);

	virtual void drawImage(const Rect& rectangle, const Image& image);

	virtual void drawImage(const Point& point, const Image& image);

	virtual void drawLine(const Point& pt1, const Point& pt2);

	virtual void drawPie(const Rect& rectangle, int startAngle, int spanAngle);

	virtual void drawPoint(const Point& position);

	virtual void drawPolygon(const std::vector<Point>& points);

	virtual void drawPolyline(const std::vector<Point>& points);

	virtual void drawRect(const Rect& rectangle);

	virtual void drawRoundedRect(const Rect& rect, int xRadius, int yRadius);

	virtual void drawText(const Rect& rectangle, const String& text);

	virtual void fillRect(int x, int y, int width, int height, const Color& color);

private:
	QPaintDevice* getPaintDevice();
	void setupClipRegion(QPainter& painter);
	void initPainter(QPainter& painter);
};

} // namespace duilib2

#endif // QTRENDERSYSTEM_H
