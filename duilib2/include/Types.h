#ifndef TYPES_H
#define TYPES_H

#include <duilib2_global.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Point
{
public:
	Point();
	Point(int x, int y);
	~Point();

	int mX;
	int mY;
};


class DUILIB2SHARED_EXPORT Size
{
public:
	Size();
	Size(int width, int height);
	~Size();

	int mWidth;
	int mHeight;
};

class DUILIB2SHARED_EXPORT Rect
{
public:
	Rect();
	Rect(int left, int top, int right, int bottom);
	~Rect();

	/**
	 * @brief
	 *     Whether the pt point is in the rect.
	 *
	 * @param pt
	 * @return
	 */
	bool contains(const Point& pt) const;

	int mLeft;
	int mTop;
	int mRight;
	int mBottom;
};

class DUILIB2SHARED_EXPORT Color
{
public:
	Color();
	Color(int red, int green, int blue, int alpha = 255);
	~Color();

	int mRed;
	int mGreen;
	int mBlue;
	int mAlpha;
};

} // namespace duilib2

#endif // TYPE_H
