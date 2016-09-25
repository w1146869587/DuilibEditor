#ifndef ROUNDRECT_H
#define ROUNDRECT_H

#include <duilib2_global.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT RoundRect
{
public:
    RoundRect();
    RoundRect(int x, int y, int width, int height, int xRadius, int yRadius);
    ~RoundRect();

    int mX;
    int mY;
    int mWidth;
    int mHeight;
    int mXRadius;
    int mYRadius;
};

} // namespace duilib2

#endif // ROUNDRECT_H
