#ifndef COMBO_H
#define COMBO_H

#include <duilib2_global.h>
#include <Controls/Container.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Combo : public Container
{
public:
	Combo(const String& name);
	virtual ~Combo();

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

class DUILIB2SHARED_EXPORT ComboFactory : public WindowFactory
{
public:
	ComboFactory();
	virtual ~ComboFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // COMBO_H
