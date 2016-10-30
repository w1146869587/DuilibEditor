#ifndef ACTIVEX_H
#define ACTIVEX_H

#include <duilib2_global.h>
#include <Controls/Control.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT ActiveX : public Control
{
public:
	ActiveX(const String& name);
	virtual ~ActiveX();

	/// @copydoc Window::getType
	virtual String getType() const;

	/// @copydoc Window::getWidth
	virtual int getWidth() const;

	/// @copydoc Window::getHeight
	virtual int getHeight() const;

	/// @copydoc Window::getPosition
	virtual Point getPosition() const;

protected:
	virtual void render(RenderTarget* renderTarget);

private:
	static String sTypeName;
};

class DUILIB2SHARED_EXPORT ActiveXFactory : public WindowFactory
{
public:
	ActiveXFactory();
	virtual ~ActiveXFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // ACTIVEX_H
