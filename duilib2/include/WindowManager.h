#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <Singleton.h>
#include <Window.h>
#include <WindowFactory.h>
#include <map>
#include <vector>

namespace duilib2
{

/**
 * @brief
 *     The WindowManager class
 */
class DUILIB2SHARED_EXPORT WindowManager : public Singleton<WindowManager>
{
public:
	WindowManager();
	~WindowManager();

	/**
	 * @brief
	 *     Add a window factory
	 *
	 * @param factory
	 *     The window factory to be added
	 */
	void addWindowFactory(WindowFactory* factory);

	/**
	 * @brief
	 *     Remove a window factory
	 *
	 * @param type
	 *     The type name of the window factory to be removed
	 */
	void removeWindowFactory(const String& type);

	/**
	 * @brief
	 *     Remove a window factory
	 *
	 * @param factory
	 *     The pointer of the window factory to be removed.
	 */
	void removeWindowFactory(WindowFactory* factory);

	/**
	 * @brief
	 *     Remove all window factories
	 */
	void removeAllWindowFactories();

	/**
	 * @brief
	 *     Create a new window
	 *
	 * @param type
	 *     The type of the new window, e.g. PushButton
	 *
	 * @param name
	 *     The ID name of the new window
	 *
	 * @return
	 *     The pointer of the new window
	 */
	Window* createWindow(const String& type, const String& name);

	/**
	 * @brief
	 *     Destroy a window by a pointer
	 *
	 * @param window
	 *     The pointer of the window to be destroyed
	 */
	void destroyWindow(Window* window);

	/**
	 * @brief
	 *     Destroy all windows that the WindowManager managed
	 */
	void destroyAllWindows();

	/**
	 * @brief
	 *     Load windows layout from a xml file
	 *
	 * @param fileName
	 *     The xml file name
	 *
	 * @return
	 *     Return the root window of the windows layout
	 */
	Window* loadLayoutFromFile(const String& fileName);

private:
	String generateUniqueWindowName();

private:
	typedef std::map<String, WindowFactory*> WindowFactoryMap;

	WindowFactoryMap mWindowFactories;
	std::vector<Window*> mWindows;
	int mUidCounter;
};

} // namespace duilib2

#endif // WINDOWMANAGER_H
