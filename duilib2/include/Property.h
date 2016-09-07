#ifndef PROPERTY_H
#define PROPERTY_H

#include <duilib2_global.h>
#include <boost/any.hpp>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Property
{
public:
	Property();
	Property(const String& name, const String& value);
	~Property();

	/**
	 * @brief
	 *     Get the name of the property.
	 *
	 * @return
	 *     The name of the property.
	 */
	String getName() const;

	// ...
	String getType() const;

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
	 *     Set the name of the property.
	 *
	 * @param name
	 *     The name of the property.
	 */
	void setName(const String& name);

	// ...
	void setType(const String& type);

	/**
	 * @brief
	 *     Set the value of the property.
	 *
	 * @param value
	 *     The value of the property.
	 */
	void setValue(const String& value);

private:
	String mName;
	String mValue;
	boost::any mAnyValue;
};

}

#endif // PROPERTY_H
