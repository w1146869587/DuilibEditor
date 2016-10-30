#ifndef OPTION_H
#define OPTION_H

#include <duilib2_global.h>
#include <Controls/Button.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Option : public Button
{
public:
	Option(const String& name);
	virtual ~Option();

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

class DUILIB2SHARED_EXPORT OptionFactory : public WindowFactory
{
public:
	OptionFactory();
	virtual ~OptionFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // OPTION_H
