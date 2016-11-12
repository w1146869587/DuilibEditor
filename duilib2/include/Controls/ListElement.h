#ifndef LISTELEMENT_H
#define LISTELEMENT_H

#include <duilib2_global.h>
#include <Controls/Control.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT ListElement : public Control
{
public:
	ListElement(const String& name);
	virtual ~ListElement();

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

class DUILIB2SHARED_EXPORT ListElementFactory : public WindowFactory
{
public:
	ListElementFactory();
	virtual ~ListElementFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // LISTELEMENT_H
