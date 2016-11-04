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

	/// @copydoc RenderSystem::fillRect
	virtual void fillRect(int x, int y, int width, int height, const Color& color);

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
