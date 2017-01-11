#ifndef RENDERSYSTEMPROXY_H
#define RENDERSYSTEMPROXY_H

#include <duilib2_global.h>
#include <RenderTarget.h>
#include <PropertyTypes.h>
#include <vector>

namespace duilib2
{

class RenderSystemImpl
{
public:
	RenderSystemImpl(RenderTarget* rt);
	virtual ~RenderSystemImpl();

	virtual void drawArc(const Rect& rectangle, int startAngle, int spanAngle) = 0;
	virtual void drawChord(const Rect& rectangle, int startAngle, int spanAngle) = 0;
	virtual void drawEllipse(const Rect& rectangle) = 0;
	virtual void drawImage(const Rect& rectangle, const Image& image, const Rect& source) = 0;
	virtual void drawImage(const Point& point, const Image& image, const Rect& source) = 0;
	virtual void drawImage(const Rect& rectangle, const Image& image) = 0;
	virtual void drawImage(const Point& point, const Image& image) = 0;
	virtual void drawLine(const Point& pt1, const Point& pt2) = 0;
	virtual void drawPie(const Rect& rectangle, int startAngle, int spanAngle) = 0;
	virtual void drawPoint(const Point& position) = 0;
	virtual void drawPolygon(const std::vector<Point>& points) = 0;
	virtual void drawPolyline(const std::vector<Point>& points) = 0;
	virtual void drawRect(const Rect& rectangle) = 0;
	virtual void drawRoundedRect(const Rect& rect, int xRadius, int yRadius) = 0;
	virtual void drawText(const Rect& rectangle, const String& text) = 0;
	virtual void fillRect(int x, int y, int width, int height, const Color& color) = 0;

	void setPenColor(const Color& color);
	Color getPenColor() const;

	void setBrushColor(const Color& color);
	Color getBrushColor() const;

	void clearClipRegion();

	bool hasClipRegion() const;

	void setClipRegion(const RoundRect& clipRegion);
	RoundRect getClipRegion() const;

	void setRenderTarget(RenderTarget* renderTarget);
	RenderTarget* getRenderTarget();

private:
	RenderTarget* mRenderTarget;
	RoundRect     mClipRegion;
	Color         mPenColor;
	Color         mBrushColor;
	bool          mHasClipRegion;
};

} // namespace duilib2

#endif // RENDERSYSTEMPROXY_H
