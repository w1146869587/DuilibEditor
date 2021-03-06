#ifndef LISTTEXTELEMENT_H
#define LISTTEXTELEMENT_H

#include <duilib2_global.h>
#include <Controls/ListLabelElement.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT ListTextElement : public ListLabelElement
{
public:
	ListTextElement(const String& name);
	virtual ~ListTextElement();

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

class DUILIB2SHARED_EXPORT ListTextElementFactory : public WindowFactory
{
public:
	ListTextElementFactory();
	virtual ~ListTextElementFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // LISTTEXTELEMENT_H
