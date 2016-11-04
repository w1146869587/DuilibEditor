#ifndef WEBBROWSER_H
#define WEBBROWSER_H

#include <duilib2_global.h>
#include <Controls/ActiveX.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT WebBrowser : public ActiveX
{
public:
	WebBrowser(const String& name);
	virtual ~WebBrowser();

	/// @copydoc Window::getType
	virtual String getType() const;

	/// @copydoc Window::getWidth
	virtual int getWidth() const;

	/// @copydoc Window::getHeight
	virtual int getHeight() const;

	/// @copydoc Window::getPosition
	virtual Point getPosition() const;

protected:
	virtual void render();

private:
	static String sTypeName;
};

class DUILIB2SHARED_EXPORT WebBrowserFactory : public WindowFactory
{
public:
	WebBrowserFactory();
	virtual ~WebBrowserFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // WEBBROWSER_H
