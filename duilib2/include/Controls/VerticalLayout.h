#ifndef VERTICALLAYOUT_H
#define VERTICALLAYOUT_H

#include <duilib2_global.h>
#include <Controls/Container.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT VerticalLayout : public Container
{
public:
	VerticalLayout(const String& name);
	virtual ~VerticalLayout();

	/// @copydoc Window::getType
	virtual String getType() const;

	/// @copydoc Window::getWidth
	virtual int getWidth() const;

	/// @copydoc Window::getHeight
	virtual int getHeight() const;

protected:
	virtual void updateLayout();

private:
	int getControlHeight() const;

private:
	static String sTypeName;
};

class DUILIB2SHARED_EXPORT VerticalLayoutFactory : public WindowFactory
{
public:
	VerticalLayoutFactory();
	virtual ~VerticalLayoutFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // VERTICALLAYOUT_H
