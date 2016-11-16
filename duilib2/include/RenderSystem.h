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

	/**
	 * @brief drawArc
	 * @param rectangle
	 * @param startAngle
	 * @param spanAngle
	 */
	virtual void drawArc(const Rect& rectangle, int startAngle, int spanAngle) = 0;

	/**
	 * @brief drawChord
	 * @param rectangle
	 * @param startAngle
	 * @param spanAngle
	 */
	virtual void drawChord(const Rect& rectangle, int startAngle, int spanAngle) = 0;

	/**
	 * @brief drawEllipse
	 * @param rectangle
	 */
	virtual void drawEllipse(const Rect& rectangle) = 0;

	/**
	 * @brief drawImage
	 * @param rectangle
	 * @param image
	 * @param source
	 */
	virtual void drawImage(const Rect& rectangle, const Image& image, const Rect& source) = 0;

	/**
	 * @brief drawImage
	 * @param point
	 * @param image
	 * @param source
	 */
	virtual void drawImage(const Point& point, const Image& image, const Rect& source) = 0;

	/**
	 * @brief drawImage
	 * @param rectangle
	 * @param image
	 */
	virtual void drawImage(const Rect& rectangle, const Image& image) = 0;

	/**
	 * @brief drawImage
	 * @param point
	 * @param image
	 */
	virtual void drawImage(const Point& point, const Image& image) = 0;

	/**
	 * @brief drawLine
	 * @param pt1
	 * @param pt2
	 */
	virtual void drawLine(const Point& pt1, const Point& pt2) = 0;

	/**
	 * @brief drawPie
	 * @param rectangle
	 * @param startAngle
	 * @param spanAngle
	 */
	virtual void drawPie(const Rect& rectangle, int startAngle, int spanAngle) = 0;

	/**
	 * @brief drawPoint
	 * @param position
	 */
	virtual void drawPoint(const Point& position) = 0;

	/**
	 * @brief drawPolygon
	 * @param points
	 */
	virtual void drawPolygon(const std::vector<Point>& points) = 0;

	/**
	 * @brief drawPolyline
	 * @param points
	 */
	virtual void drawPolyline(const std::vector<Point>& points) = 0;

	/**
	 * @brief drawRect
	 * @param rectangle
	 */
	virtual void drawRect(const Rect& rectangle) = 0;

	/**
	 * @brief drawRoundedRect
	 * @param rect
	 * @param xRadius
	 * @param yRadius
	 */
	virtual void drawRoundedRect(const Rect& rect, int xRadius, int yRadius) = 0;

	/**
	 * @brief drawText
	 * @param rectangle
	 * @param text
	 */
	virtual void drawText(const Rect& rectangle, const String& text) = 0;

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
