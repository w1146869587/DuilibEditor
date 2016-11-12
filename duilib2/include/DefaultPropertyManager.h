#ifndef DEFAULTPROPERTYMANAGER_H
#define DEFAULTPROPERTYMANAGER_H

#include <duilib2_global.h>
#include <Singleton.h>

namespace duilib2
{

class DefaultPropertyManager : public Singleton<DefaultPropertyManager>
{
public:
	DefaultPropertyManager();
	~DefaultPropertyManager();

};

}

#endif // DEFAULTPROPERTYMANAGER_H
