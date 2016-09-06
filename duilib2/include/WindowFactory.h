#ifndef WINDOWFACTORY_H
#define WINDOWFACTORY_H

#include <duilib2_global.h>
#include <Window.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT WindowFactory
{
public:
	WindowFactory();
	virtual ~WindowFactory();

	/**
	 * @brief
	 *     Get the type name of the window factory
	 *
	 * @return
	 *     The name of the window factory
	 */
	virtual String getType() const = 0;

	/**
	 * @brief
	 *     Create a new window
	 *
	 * @param name
	 *     The ID name of the window
	 *
	 * @return
	 *     The pointer of the new window
	 */
	virtual Window* createInstance(const String& name) = 0;

	/**
	 * @brief
	 *     Destroy a window (delete)
	 *
	 * @param window
	 *     The pointer of the window
	 */
	virtual void destroyInstance(Window* window) = 0;
};

}

#endif // WINDOWFACTORY_H
