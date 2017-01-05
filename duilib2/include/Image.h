#ifndef IMAGE_H
#define IMAGE_H

#include <duilib2_global.h>
#include <PropertyTypes.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Image
{
public:
	Image();
	~Image();

	String getFileName() const;
	String getRes() const;
	String getResType() const;
	Rect   getDest() const;
	Rect   getSource() const;
	Color  getMaskColor() const;
	int    getFadeValue() const;
	bool   isHole() const;
	bool   isXTiled() const;
	bool   isYTiled() const;

	void setFileName(const String& filename);
	void setRes(const String& res);
	void setResType(const String& resType);
	void setDest(const Rect& rect);
	void setSource(const Rect& rect);
	void setMaskColor(const Color& color);
	void setFadeValue(int value);
	void setIsHole(bool value);
	void setIsXTiled(bool value);
	void setIsYTiled(bool value);

private:
	String mFileName; // file='aaa.jpg'
	String mRes;      // res=''
	String mResType;  // restype='0'
	Rect   mDest;     // dest='0,0,0,0'
	Rect   mSource;   // source='0,0,0,0'
	Rect   mCorner;   // corner='0,0,0,0'
	Color  mMask;     // mask='#FF0000'
	int    mFade;     // fade='255'
	bool   mHole;     // hole='false'
	bool   mXTiled;   // xtiled='false'
	bool   mYTiled;   // ytiled='false'
};

} // namespace duilib2

#endif // IMAGE_H
