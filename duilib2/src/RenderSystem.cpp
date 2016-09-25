#include <RenderSystem.h>

namespace duilib2
{

RenderSystem::RenderSystem()
	: mClipping(false)
	, mRenderTarget(NULL)
{

}

RenderSystem::~RenderSystem()
{

}

void RenderSystem::setRenderTarget(RenderTarget* renderTarget)
{
	mRenderTarget = renderTarget;
}

RenderTarget* RenderSystem::getRenderTarget()
{
	return mRenderTarget;
}

void RenderSystem::clearClipRegion()
{
	mClipping = false;
}

void RenderSystem::setClipRegion(const RoundRect& clipRegion)
{
	mClipping = true;
	mClipRegion = clipRegion;
}

RoundRect RenderSystem::getClipRegion() const
{
	return mClipRegion;
}

bool RenderSystem::hasClipRegion() const
{
	return mClipping;
}

} // namespace duilib2
