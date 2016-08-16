#include <WindowManager.h>

namespace duilib2
{

WindowManager* Singleton<WindowManager>::mSingleton = NULL;

WindowManager::WindowManager()
{

}

WindowManager::~WindowManager()
{

}

Window* WindowManager::loadLayoutFromFile(const String& fileName)
{
	return NULL;
}


} // namespace duilib2
