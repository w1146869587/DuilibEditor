#ifndef PROPERTY_H
#define PROPERTY_H

#include <duilib2_global.h>
#include <boost/any.hpp>
#include <Exception.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Property
{
public:
	Property();
	Property(const String& name, const String& value, const String& type = "");
	~Property();

	/**
	 * @brief
	 *     Get the name of the property.
	 *
	 * @return
	 *     The name of the property.
	 */
	String getName() const;

	/**
	 * @brief
	 *     Get the value of the property.
	 *
	 * @return
	 *     The value of the property.
	 */
	String getValue() const;

	/**
	 * @brief
	 *     Get the type of the property.
	 *
	 * @return
	 *     The type of the property.
	 */
	String getType() const;

	/**
	 * @brief
	 *     Get concrete value.
	 *
	 * @return
	 *     The concrete value.
	 */
	template<typename T>
	T getAnyValue() const;

	/**
	 * @brief
	 *     Set the name of the property.
	 *
	 * @param name
	 *     The name of the property.
	 */
	void setName(const String& name);

	/**
	 * @brief
	 *     Set the value of the property.
	 *
	 * @param value
	 *     The value of the property.
	 */
	void setValue(const String& value);

	/**
	 * @brief
	 *     Set the type of the property.
	 *
	 * @param type
	 *     The type of the property.
	 */
	void setType(const String& type);

	/**
	 * @brief
	 *     Set the concrete value.
	 *
	 * @param type
	 *     The concrete value.
	 */
	template<typename T>
	void setAnyValue(const T& value);

	/**
	 * @brief
	 *     Parsing the value string, convert to the concrete type.
	 */
	void initialize();

private:
	String mName;
	String mValue;
	String mType;
	boost::any mAnyValue;
};

template<typename T>
T Property::getAnyValue() const
{
	const T* value = boost::any_cast<T>(&mAnyValue);
	if (value == NULL)
	{
		DUILIB2_EXCEPT(Exception::ERR_INTERNAL_ERROR,
							 "There is no value of this type",
							 "Property::getAnyValue");
	}

	return *value;
}

template<typename T>
void Property::setAnyValue(const T& value)
{
	mAnyValue = value;
}

}

#endif // PROPERTY_H
