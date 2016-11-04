#ifndef SLIDER_H
#define SLIDER_H

#include <duilib2_global.h>
#include <Controls/Progress.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Slider : public Progress
{
public:
	Slider(const String& name);
	virtual ~Slider();

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

class DUILIB2SHARED_EXPORT SliderFactory : public WindowFactory
{
public:
	SliderFactory();
	virtual ~SliderFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // SLIDER_H
