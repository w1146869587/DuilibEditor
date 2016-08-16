#ifndef SYSTEM_H
#define SYSTEM_H

#include <duilib2_global.h>
#include <Singleton.h>
#include <ResourceManager.h>
#include <WindowManager.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT System : public Singleton<System>
{
public:
	System();
	~System();

	static System* create();
	static void destroy();

private:
	ResourceManager* mResourceManager;
	WindowManager*   mWindowManager;
};

} // duilib2

#endif // SYSTEM_H
