#ifndef LISTBODY_H
#define LISTBODY_H

#include <duilib2_global.h>
#include <Controls/VerticalLayout.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT ListBody : public VerticalLayout
{
public:
	ListBody(const String& name);
	virtual ~ListBody();

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

class DUILIB2SHARED_EXPORT ListBodyFactory : public WindowFactory
{
public:
	ListBodyFactory();
	virtual ~ListBodyFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // LISTBODY_H
