#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <duilib2_global.h>
#include <RenderTarget.h>
#include <RoundRect.h>
#include <PropertyTypes.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT RenderSystem
{
public:
	RenderSystem();
	~RenderSystem();

	/**
	 * @brief reset
	 */
	virtual void reset();

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

	/**
	 * @brief fillRect
	 * @param x
	 * @param y
	 * @param width
	 * @param height
	 * @param color
	 */
	virtual void fillRect(int x, int y, int width, int height, const Color& color) = 0;

	/**
	 * @brief setRenderTarget
	 * @param renderTarget
	 */
	virtual void setRenderTarget(RenderTarget* renderTarget);

	/**
	 * @brief getRenderTarget
	 * @return
	 */
	virtual RenderTarget* getRenderTarget();

	/**
	 * @brief clearClipRegion
	 */
	virtual void clearClipRegion();

	/**
	 * @brief setClipRegion
	 * @param clipRegion
	 */
	virtual void setClipRegion(const RoundRect& clipRegion);

	/**
	 * @brief getClipRegion
	 * @return
	 */
	virtual RoundRect getClipRegion() const;

	/**
	 * @brief hasClipRegion
	 * @return
	 */
	virtual bool hasClipRegion() const;


private:
	bool mClipping;
	RoundRect mClipRegion;
	RenderTarget* mRenderTarget;
};

} // namespace duilib2

#endif // RENDERSYSTEM_H
