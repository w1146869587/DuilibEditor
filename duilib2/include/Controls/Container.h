#ifndef CONTAINER_H
#define CONTAINER_H

#include <duilib2_global.h>
#include <Controls/Control.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Container : public Control
{
public:
	Container(const String& name);
	virtual ~Container();

	/// @copydoc Window::getType
	virtual String getType() const;

	/**
	 * @brief getChildPadding
	 * @return
	 */
	int getChildPadding() const;

protected:
	virtual void render();
	virtual void updateLayout();

private:
	static String sTypeName;
};

class DUILIB2SHARED_EXPORT ContainerFactory : public WindowFactory
{
public:
	ContainerFactory();
	virtual ~ContainerFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // CONTAINER_H
