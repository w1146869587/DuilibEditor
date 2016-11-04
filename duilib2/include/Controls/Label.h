#ifndef LABEL_H
#define LABEL_H

#include <duilib2_global.h>
#include <Controls/Control.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Label : public Control
{
public:
	Label(const String& name);
	virtual ~Label();

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

class DUILIB2SHARED_EXPORT LabelFactory : public WindowFactory
{
public:
	LabelFactory();
	virtual ~LabelFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // LABEL_H
