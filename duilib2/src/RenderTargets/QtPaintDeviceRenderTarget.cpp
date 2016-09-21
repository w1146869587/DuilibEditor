#include <RenderTargets/QtPaintDeviceRenderTarget.h>

namespace duilib2
{

QtPaintDeviceRenderTarget::QtPaintDeviceRenderTarget(QPaintDevice* paintDevice)
	: mPaintDevice(paintDevice)
{

}

QtPaintDeviceRenderTarget::~QtPaintDeviceRenderTarget()
{

}

QPaintDevice* QtPaintDeviceRenderTarget::getPaintDevice()
{
	return mPaintDevice;
}

} // namespace duilib2

