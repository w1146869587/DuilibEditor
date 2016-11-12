#ifndef GIFANIM_H
#define GIFANIM_H

#include <duilib2_global.h>
#include <Controls/Control.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT GifAnim : public Control
{
public:
	GifAnim(const String& name);
	virtual ~GifAnim();

	/// @copydoc Window::getType
	virtual String getType() const;

	/// @copydoc Window::getWidth
	virtual int getWidth() const;

	/// @copydoc Window::getHeight
	virtual int getHeight() const;

	/// @copydoc Window::getPosition
	virtual Point getPosition() const;

protected:

private:
	static String sTypeName;
};

class DUILIB2SHARED_EXPORT GifAnimFactory : public WindowFactory
{
public:
	GifAnimFactory();
	virtual ~GifAnimFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // GIFANIM_H
