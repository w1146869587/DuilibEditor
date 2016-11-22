#include <RenderSystem.h>

namespace duilib2
{

RenderSystem::RenderSystem()
	: mClipping(false)
	, mRenderTarget(NULL)
	, mPenColor(0, 0, 0)
	, mBrushColor(0, 0, 0)
{

}

RenderSystem::~RenderSystem()
{

}

void RenderSystem::reset()
{
	clearClipRegion();
	setRenderTarget(NULL);
}

void RenderSystem::setPenColor(const Color& color)
{
	mPenColor = color;
}

Color RenderSystem::getPenColor() const
{
	return mPenColor;
}

void RenderSystem::setBrushColor(const Color& color)
{
	mBrushColor = color;
}

Color RenderSystem::getBrushColor() const
{
	return mBrushColor;
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
