#ifndef DATETIME_H
#define DATETIME_H

#include <duilib2_global.h>
#include <Controls/Label.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT DateTime : public Label
{
public:
	DateTime(const String& name);
	virtual ~DateTime();

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

class DUILIB2SHARED_EXPORT DateTimeFactory : public WindowFactory
{
public:
	DateTimeFactory();
	virtual ~DateTimeFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // DATETIME_H
