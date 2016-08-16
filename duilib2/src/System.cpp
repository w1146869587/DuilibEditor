#include "System.h"

namespace duilib2
{

System* Singleton<System>::mSingleton = NULL;

System::System()
{
	// 初始化ResourceManager等

	mResourceManager = new ResourceManager;
	mWindowManager = new WindowManager;
}

System::~System()
{
	delete mWindowManager;
	delete mResourceManager;
}

System* System::create()
{
	return new System();
}

void System::destroy()
{
	delete mSingleton;
}

} // duilib2
