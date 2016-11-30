#ifndef QTPAINTDEVICERENDERTARGET_H
#define QTPAINTDEVICERENDERTARGET_H

#include <duilib2_global.h>
#include <RenderTarget.h>
#include <QPaintDevice>

namespace duilib2
{

class QtPaintDeviceRenderTarget : public RenderTarget
{
public:
	QtPaintDeviceRenderTarget(QPaintDevice* paintDevice);
	virtual ~QtPaintDeviceRenderTarget();

	/**
	 * @brief getPaintDevice
	 * @return
	 */
	QPaintDevice* getPaintDevice();

private:
	QPaintDevice* mPaintDevice;
};

} // namespace duilib2

#endif // QTPAINTDEVICERENDERTARGET_H
