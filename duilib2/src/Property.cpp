#include <Property.h>
#include <PropertyParserManager.h>
#include <Exception.h>

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

template<typename T>
T Property::getAnyValue() const
{
	T* value = boost::any_cast<T>(&mAnyValue);
	if (value == NULL)
	{
		DUILIB2_EXCEPT(Exception::ERR_INTERNAL_ERROR,
							 "There is no value of this type",
							 "Property::getAnyValue");
	}

	return *value;
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

void Property::initialize()
{
	PropertyParserManager::getSingleton().parse(*this);
}

template<typename T>
void Property::setAnyValue(const T& value)
{
	mAnyValue = value;
}

}
