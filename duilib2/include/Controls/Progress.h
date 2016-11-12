#ifndef PROGRESS_H
#define PROGRESS_H

#include <duilib2_global.h>
#include <Controls/Label.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Progress : public Label
{
public:
	Progress(const String& name);
	virtual ~Progress();

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

class DUILIB2SHARED_EXPORT ProgressFactory : public WindowFactory
{
public:
	ProgressFactory();
	virtual ~ProgressFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // PROGRESS_H
