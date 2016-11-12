#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <duilib2_global.h>
#include <Controls/Option.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT CheckBox : public Option
{
public:
	CheckBox(const String& name);
	virtual ~CheckBox();

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

class DUILIB2SHARED_EXPORT CheckBoxFactory : public WindowFactory
{
public:
	CheckBoxFactory();
	virtual ~CheckBoxFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // CHECKBOX_H
