#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <duilib2_global.h>
#include <RenderTarget.h>
#include <PropertyTypes.h>
#include <RenderSystemImpl.h>


namespace duilib2
{

class RenderSystemImpl;

class DUILIB2SHARED_EXPORT RenderSystem
{
public:
	RenderSystem(RenderTarget* rt);
	~RenderSystem();

	/**
	 * @brief drawArc
	 * @param rectangle
	 * @param startAngle
	 * @param spanAngle
	 */
	virtual void drawArc(const Rect& rectangle, int startAngle, int spanAngle);

	/**
	 * @brief drawChord
	 * @param rectangle
	 * @param startAngle
	 * @param spanAngle
	 */
	virtual void drawChord(const Rect& rectangle, int startAngle, int spanAngle);

	/**
	 * @brief drawEllipse
	 * @param rectangle
	 */
	virtual void drawEllipse(const Rect& rectangle);

	/**
	 * @brief drawImage
	 * @param rectangle
	 * @param image
	 * @param source
	 */
	virtual void drawImage(const Rect& rectangle, const Image& image, const Rect& source);

	/**
	 * @brief drawImage
	 * @param point
	 * @param image
	 * @param source
	 */
	virtual void drawImage(const Point& point, const Image& image, const Rect& source);

	/**
	 * @brief drawImage
	 * @param rectangle
	 * @param image
	 */
	virtual void drawImage(const Rect& rectangle, const Image& image);

	/**
	 * @brief drawImage
	 * @param point
	 * @param image
	 */
	virtual void drawImage(const Point& point, const Image& image);

	/**
	 * @brief drawLine
	 * @param pt1
	 * @param pt2
	 */
	virtual void drawLine(const Point& pt1, const Point& pt2);

	/**
	 * @brief drawPie
	 * @param rectangle
	 * @param startAngle
	 * @param spanAngle
	 */
	virtual void drawPie(const Rect& rectangle, int startAngle, int spanAngle);

	/**
	 * @brief drawPoint
	 * @param position
	 */
	virtual void drawPoint(const Point& position);

	/**
	 * @brief drawPolygon
	 * @param points
	 */
	virtual void drawPolygon(const std::vector<Point>& points);

	/**
	 * @brief drawPolyline
	 * @param points
	 */
	virtual void drawPolyline(const std::vector<Point>& points);

	/**
	 * @brief drawRect
	 * @param rectangle
	 */
	virtual void drawRect(const Rect& rectangle);

	/**
	 * @brief drawRoundedRect
	 * @param rect
	 * @param xRadius
	 * @param yRadius
	 */
	virtual void drawRoundedRect(const Rect& rect, int xRadius, int yRadius);

	/**
	 * @brief drawText
	 * @param rectangle
	 * @param text
	 */
	virtual void drawText(const Rect& rectangle, const String& text);

	/**
	 * @brief fillRect
	 * @param x
	 * @param y
	 * @param width
	 * @param height
	 * @param color
	 */
	virtual void fillRect(int x, int y, int width, int height, const Color& color);

	/**
	 * @brief setPenColor
	 * @param color
	 */
	virtual void setPenColor(const Color& color);

	/**
	 * @brief getPenColor
	 * @param color
	 */
	virtual Color getPenColor() const;

	/**
	 * @brief setBrushColor
	 * @param color
	 */
	virtual void setBrushColor(const Color& color);

	/**
	 * @brief getBrushColor
	 * @return
	 */
	virtual Color getBrushColor() const;

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
	RenderSystemImpl* mRenderSystemImpl;
};

} // namespace duilib2

#endif // RENDERSYSTEM_H
