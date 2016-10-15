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
	String lowerName  = name.toLower();

	std::map<String, Property>::iterator pos = mProperties.find(lowerName);
	if (pos != mProperties.end())
	{
		pos->second.setValue(value);
		if (!type.isEmpty())
			pos->second.setType(type);
	}
	else
		mProperties[lowerName] = Property(lowerName, value, type);

	mProperties[lowerName].initialize();
}

const Property& PropertySet::getProperty(const String& name) const
{
	String lowerName  = name.toLower();

	std::map<String, Property>::const_iterator pos = mProperties.find(lowerName);
	if (pos == mProperties.end())
	{
		DUILIB2_EXCEPT(Exception::ERR_ITEM_NOT_FOUND,
							 "Property named " + name + " is not exists",
							 "PropertySet::getProperty");
	}
	return pos->second;
}

}
