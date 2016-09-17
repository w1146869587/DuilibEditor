#ifndef PROPERTYTYPES_H
#define PROPERTYTYPES_H

#include <duilib2_global.h>

namespace duilib2
{

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

	int mLeft;
	int mTop;
	int mRight;
	int mBottom;
};

typedef int Byte;

typedef bool Bool;

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

#endif // PROPERTYTYPES_H
