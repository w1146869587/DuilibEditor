#ifndef PROPERTYSET_H
#define PROPERTYSET_H

#include <duilib2_global.h>
#include <Property.h>
#include <map>

namespace duilib2
{

/**
 * @brief
 *     This class manager the attributes of the window.
 */
class DUILIB2SHARED_EXPORT PropertySet
{
public:
	PropertySet();
	virtual ~PropertySet();

	/**
	 * @brief
	 *     Add a property.
	 *
	 * @param name
	 *     The name of the property.
	 *
	 * @param type
	 *     The type of the property, e.g. String, Bool
	 *
	 * @param value
	 *     The value of the property.
	 */
	void addProperty(const String& name, const String& type, const String& value);

	/**
	 * @brief
	 *     Get a property by name.
	 *
	 * @param name
	 *     The name of the property.
	 *
	 * @return
	 *     The property.
	 */
	const Property& getProperty(const String& name) const;
	Property& getProperty(const String& name);

private:
	std::map<String, Property> mProperties;
};

}

#endif // PROPERTYSET_H
