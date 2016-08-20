#ifndef SYSTEM_H
#define SYSTEM_H

#include <duilib2_global.h>
#include <Singleton.h>
#include <ResourceManager.h>
#include <WindowManager.h>
#include <XmlParser.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT System : public Singleton<System>
{
public:
	System();
	~System();

	static System* create();
	static void destroy();

	XmlParser* getXmlParser() const;

private:
	void createXmlParser();

private:
	ResourceManager* mResourceManager;
	WindowManager*   mWindowManager;
	XmlParser*       mXmlParser;
};

} // duilib2

#endif // SYSTEM_H
