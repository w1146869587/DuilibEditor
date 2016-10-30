#ifndef LISTHEADER_H
#define LISTHEADER_H

#include <duilib2_global.h>
#include <Controls/HorizontalLayout.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT ListHeader : public HorizontalLayout
{
public:
	ListHeader(const String& name);
	virtual ~ListHeader();

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

class DUILIB2SHARED_EXPORT ListHeaderFactory : public WindowFactory
{
public:
	ListHeaderFactory();
	virtual ~ListHeaderFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // LISTHEADER_H
