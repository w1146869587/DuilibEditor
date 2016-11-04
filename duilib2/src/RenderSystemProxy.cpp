#include <RenderSystemProxy.h>
#include <System.h>

namespace duilib2
{

RenderSystemProxy::RenderSystemProxy(RenderTarget* rt)
{
	mRenderSystem = System::getSingleton().getRenderSystem();
	mRenderSystem->setRenderTarget(rt);
}

RenderSystemProxy::~RenderSystemProxy()
{
	mRenderSystem->reset();
}

void RenderSystemProxy::reset()
{
	mRenderSystem->reset();
}

void RenderSystemProxy::fillRect(
		int x, int y, int width, int height, const Color& color)
{
	mRenderSystem->fillRect(x, y, width, height, color);
}

void RenderSystemProxy::setRenderTarget(RenderTarget* renderTarget)
{
	mRenderSystem->setRenderTarget(renderTarget);
}

RenderTarget* RenderSystemProxy::getRenderTarget()
{
	return mRenderSystem->getRenderTarget();
}

void RenderSystemProxy::clearClipRegion()
{
	mRenderSystem->clearClipRegion();
}

void RenderSystemProxy::setClipRegion(const RoundRect& clipRegion)
{
	mRenderSystem->setClipRegion(clipRegion);
}

RoundRect RenderSystemProxy::getClipRegion() const
{
	return mRenderSystem->getClipRegion();
}

bool RenderSystemProxy::hasClipRegion() const
{
	return mRenderSystem->hasClipRegion();
}

} // namespace duilib2
