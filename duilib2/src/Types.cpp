#include <Types.h>

namespace duilib2
{

Point::Point()
	: mX(0), mY(0)
{

}

Point::Point(int x, int y)
	: mX(x), mY(y)
{

}

Point::~Point()
{

}


Size::Size()
	: mWidth(0)
	, mHeight(0)
{

}

Size::Size(int width, int height)
	: mWidth(width)
	, mHeight(height)
{

}

Size::~Size()
{

}

Rect::Rect()
	: mLeft(0)
	, mTop(0)
	, mRight(0)
	, mBottom(0)
{

}

Rect::Rect(int left, int top, int right, int bottom)
	: mLeft(left)
	, mTop(top)
	, mRight(right)
	, mBottom(bottom)
{

}

Rect::~Rect()
{

}

bool Rect::contains(const Point& pt) const
{
	if (pt.mX < mLeft || pt.mX > mRight ||
		pt.mY < mTop || pt.mY > mBottom)
	{
		return false;
	}
	return true;
}

int Rect::getWidth() const
{
	return mRight - mLeft;
}

int Rect::getHeight() const
{
	return mBottom - mTop;
}

Color::Color()
	: mRed(0)
	, mGreen(0)
	, mBlue(0)
	, mAlpha(255)
{

}

Color::Color(int red, int green, int blue, int alpha)
	: mRed(red)
	, mGreen(green)
	, mBlue(blue)
	, mAlpha(alpha)
{

}

Color::~Color()
{

}

} // namespace duilib2

