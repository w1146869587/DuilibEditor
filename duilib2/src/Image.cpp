#include <Image.h>

namespace duilib2
{

Image::Image()
{

}

Image::~Image()
{

}

String Image::getFileName() const
{
	return mFileName;
}

String Image::getRes() const
{
	return mRes;
}

String Image::getResType() const
{
	return mResType;
}

Rect Image::getDest() const
{
	return mDest;
}

Rect Image::getSource() const
{
	return mSource;
}

Color Image::getMaskColor() const
{
	return mMask;
}

int Image::getFadeValue() const
{
	return mFade;
}

bool Image::isHole() const
{
	return mHole;
}

bool Image::isXTiled() const
{
	return mXTiled;
}

bool Image::isYTiled() const
{
	return mYTiled;
}

void Image::setFileName(const String& filename)
{
	mFileName = filename;
}

void Image::setRes(const String& res)
{
	mRes = res;
}

void Image::setResType(const String& resType)
{
	mResType = resType;
}

void Image::setDest(const Rect& rect)
{
	mDest = rect;
}

void Image::setSource(const Rect& rect)
{
	mSource = rect;
}

void Image::setMaskColor(const Color& color)
{
	mMask = color;
}

void Image::setFadeValue(int value)
{
	mFade = value;
}

void Image::setIsHole(bool value)
{
	mHole = value;
}

void Image::setIsXTiled(bool value)
{
	mXTiled = value;
}

void Image::setIsYTiled(bool value)
{
	mYTiled = value;
}


} // namespace duilib2

