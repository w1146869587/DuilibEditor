#ifndef RICHEDIT_H
#define RICHEDIT_H

#include <duilib2_global.h>
#include <Controls/Container.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT RichEdit : public Container
{
public:
	RichEdit(const String& name);
	virtual ~RichEdit();

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

class DUILIB2SHARED_EXPORT RichEditFactory : public WindowFactory
{
public:
	RichEditFactory();
	virtual ~RichEditFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // RICHEDIT_H
