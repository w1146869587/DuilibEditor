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
	std::map<String, Property>::iterator pos = mProperties.find(name);
	if (pos != mProperties.end())
	{
		pos->second.setValue(value);
		if (!type.isEmpty())
			pos->second.setType(type);
	}
	else
		mProperties[name] = Property(name, value, type);

	mProperties[name].initialize();
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

}
