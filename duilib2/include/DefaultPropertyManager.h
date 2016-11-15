#ifndef DEFAULTPROPERTYMANAGER_H
#define DEFAULTPROPERTYMANAGER_H

#include <duilib2_global.h>
#include <Singleton.h>
#include <DefaultProperty.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT DefaultPropertyManager : public Singleton<DefaultPropertyManager>
{
public:
	DefaultPropertyManager();
	~DefaultPropertyManager();

	/**
	 * @brief addDefaultProperty
	 * @param defaultProperty
	 */
	void addDefaultProperty(const DefaultProperty& defaultProperty);
};

}

#endif // DEFAULTPROPERTYMANAGER_H
