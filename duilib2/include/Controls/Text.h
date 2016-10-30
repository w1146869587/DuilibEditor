#ifndef TEXT_H
#define TEXT_H

#include <duilib2_global.h>
#include <Controls/Label.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Text : public Label
{
public:
	Text(const String& name);
	virtual ~Text();

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

class DUILIB2SHARED_EXPORT TextFactory : public WindowFactory
{
public:
	TextFactory();
	virtual ~TextFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // TEXT_H
