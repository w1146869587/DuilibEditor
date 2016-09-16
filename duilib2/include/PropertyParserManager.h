#ifndef PROPERTYPARSERMANAGER_H
#define PROPERTYPARSERMANAGER_H

#include <duilib2_global.h>
#include <Singleton.h>
#include <map>
#include <PropertyParsers.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT PropertyParserManager : public Singleton<PropertyParserManager>
{
public:
	PropertyParserManager();
	~PropertyParserManager();

private:
	std::map<String, PropertyParser> mPropertyParsers;
};

} // namespace duilib2

#endif // PROPERTYPARSERMANAGER_H
