#ifndef LISTLABELELEMENT_H
#define LISTLABELELEMENT_H

#include <duilib2_global.h>
#include <Controls/ListElement.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT ListLabelElement : public ListElement
{
public:
	ListLabelElement(const String& name);
	virtual ~ListLabelElement();

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

class DUILIB2SHARED_EXPORT ListLabelElementFactory : public WindowFactory
{
public:
	ListLabelElementFactory();
	virtual ~ListLabelElementFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // LISTLABELELEMENT_H
