#include <RoundRect.h>

namespace duilib2
{

RoundRect::RoundRect()
    : mX(0)
    , mY(0)
    , mWidth(0)
    , mHeight(0)
    , mXRadius(0)
    , mYRadius(0)
{

}

RoundRect::RoundRect(int x, int y, int width, int height, int xRadius, int yRadius)
    : mX(x)
    , mY(y)
    , mWidth(width)
    , mHeight(height)
    , mXRadius(xRadius)
    , mYRadius(yRadius)
{

}

RoundRect::~RoundRect()
{

}

} // namespace duilib2
