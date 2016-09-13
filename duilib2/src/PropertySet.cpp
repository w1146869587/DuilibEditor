#include "PropertySet.h"
#include <Exception.h>

namespace duilib2
{

PropertySet::PropertySet()
{

}

PropertySet::~PropertySet()
{

}

void PropertySet::addProperty(const String& name, const String& value, const String& type)
{
	mProperties[name] = Property(name, value, type);
}

const Property& PropertySet::getProperty(const String& name) const
{
	std::map<String, Property>::const_iterator pos = mProperties.find(name);
	if (pos == mProperties.end())
	{
		DUILIB2_EXCEPT(Exception::ERR_ITEM_NOT_FOUND,
							 "Property named" + name + "is not exists",
							 "PropertySet::getProperty");
	}
	return pos->second;
}

Property& PropertySet::getProperty(const String& name)
{

	std::map<String, Property>::iterator pos = mProperties.find(name);
	if (pos == mProperties.end())
	{
		DUILIB2_EXCEPT(Exception::ERR_ITEM_NOT_FOUND,
							 "Property named" + name + "is not exists",
							 "PropertySet::getProperty");
	}
	return pos->second;
}

void PropertySet::initialize()
{
	std::map<String, Property>::iterator iter;
	for (iter = mProperties.begin(); iter != mProperties.end(); ++iter)
	{
		//PropertyParser* parser = PropertyParserManager::getSingleton().getParser(name);
		//parser.parse(iter->second);
	}
}

}
