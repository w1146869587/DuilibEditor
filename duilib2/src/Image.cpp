#include <Image.h>
#include "ImageImpl/Qt_ImageImpl.h"

namespace duilib2
{

Image::Image()
{
	mImpl = new Qt_ImageImpl;
}

Image::~Image()
{
	delete mImpl;
}

} // namespace duilib2

