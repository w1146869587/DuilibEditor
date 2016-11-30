#ifndef IMAGE_H
#define IMAGE_H

#include <duilib2_global.h>

namespace duilib2
{

class ImageImpl;

class DUILIB2SHARED_EXPORT Image
{
public:
	Image();
	~Image();

private:
	ImageImpl* mImpl;
};

} // namespace duilib2

#endif // IMAGE_H
