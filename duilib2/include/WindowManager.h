#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <Singleton.h>
#include <Window.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT WindowManager : public Singleton<WindowManager>
{
public:
	WindowManager();
	~WindowManager();

	Window* loadLayoutFromFile(const String& fileName);

private:
};

} // namespace duilib2

#endif // WINDOWMANAGER_H
