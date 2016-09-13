#include <Property.h>

namespace duilib2
{

Property::Property()
{

}

Property::Property(const String& name, const String& value, const String& type)
	: mName(name)
	, mValue(value)
	, mType(type)
{

}

Property::~Property()
{

}

String Property::getName() const
{
	return mName;
}

String Property::getValue() const
{
	return mValue;
}

String Property::getType() const
{
	return mType;
}

void Property::setName(const String& name)
{
	mName = name;
}

void Property::setValue(const String& value)
{
	mValue = value;
	mAnyValue.clear();
}

void Property::setType(const String& type)
{
	mType = type;
}

}
