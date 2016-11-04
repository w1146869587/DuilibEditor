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
