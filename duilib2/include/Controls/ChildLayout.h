#ifndef CHILDLAYOUT_H
#define CHILDLAYOUT_H

#include <duilib2_global.h>
#include <Controls/Container.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT ChildLayout : public Container
{
public:
	ChildLayout(const String& name);
	virtual ~ChildLayout();

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

class DUILIB2SHARED_EXPORT ChildLayoutFactory : public WindowFactory
{
public:
	ChildLayoutFactory();
	virtual ~ChildLayoutFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // CHILDLAYOUT_H
