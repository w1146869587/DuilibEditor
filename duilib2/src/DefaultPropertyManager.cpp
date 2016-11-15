#include <DefaultPropertyManager.h>

namespace duilib2
{

DefaultPropertyManager* Singleton<DefaultPropertyManager>::mSingleton = NULL;

DefaultPropertyManager::DefaultPropertyManager()
{

}

DefaultPropertyManager::~DefaultPropertyManager()
{

}

void DefaultPropertyManager::addDefaultProperty(const DefaultProperty& defaultProperty)
{
	// ...
}

} // namespace duilib2

