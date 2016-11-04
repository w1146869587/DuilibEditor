#ifndef LIST_H
#define LIST_H

#include <duilib2_global.h>
#include <Controls/VerticalLayout.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT List : public VerticalLayout
{
public:
	List(const String& name);
	virtual ~List();

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

class DUILIB2SHARED_EXPORT ListFactory : public WindowFactory
{
public:
	ListFactory();
	virtual ~ListFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // LIST_H
