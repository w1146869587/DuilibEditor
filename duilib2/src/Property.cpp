#include <Property.h>

namespace duilib2
{

Property::Property()
{

}

Property::Property(const String& name, const String& value)
	: mName(name)
	, mValue(value)
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

void Property::setName(const String& name)
{
	mName = name;
}

void Property::setValue(const String& value)
{
	mValue = value;
	mAnyValue.clear();
}

}
