#include <RenderSystemImpl.h>
#include <System.h>

namespace duilib2
{

RenderSystemImpl::RenderSystemImpl(RenderTarget* rt)
	: mRenderTarget(rt)
	, mPenColor(0, 0, 0)
	, mBrushColor(0, 0, 0)
	, mHasClipRegion(false)
{
}

RenderSystemImpl::~RenderSystemImpl()
{
}

void RenderSystemImpl::setPenColor(const Color& color)
{
	mPenColor = color;
}

Color RenderSystemImpl::getPenColor() const
{
	return mPenColor;
}

void RenderSystemImpl::setBrushColor(const Color& color)
{
	mBrushColor = color;
}

Color RenderSystemImpl::getBrushColor() const
{
	return mBrushColor;
}

void RenderSystemImpl::clearClipRegion()
{
	mHasClipRegion = false;
}

bool RenderSystemImpl::hasClipRegion() const
{
	return mHasClipRegion;
}

void RenderSystemImpl::setClipRegion(const RoundRect& clipRegion)
{
	mClipRegion = clipRegion;
	mHasClipRegion = true;
}

RoundRect RenderSystemImpl::getClipRegion() const
{
	return mClipRegion;
}

void RenderSystemImpl::setRenderTarget(RenderTarget* renderTarget)
{
	mRenderTarget = renderTarget;
}

RenderTarget* RenderSystemImpl::getRenderTarget()
{
	return mRenderTarget;
}

} // namespace duilib2
