#ifndef PROPERTYPARSERMANAGER_H
#define PROPERTYPARSERMANAGER_H

#include <duilib2_global.h>
#include <Singleton.h>
#include <map>
#include <PropertyParsers.h>
#include <Property.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT PropertyParserManager : public Singleton<PropertyParserManager>
{
public:
	PropertyParserManager();
	~PropertyParserManager();

	/**
	 * @brief
	 *     Get the property parser of \a type.
	 *
	 * @param type
	 *     The type of the property parser.
	 *
	 * @return
	 *     The property parser.
	 */
	const PropertyParser* getParser(const String& type) const;

	/**
	 * @brief
	 *     Parse the property.
	 *
	 * @param property
	 *     The property to be parse.
	 *
	 * @return
	 *     The reference of the parameter \a property.
	 */
	Property& parse(Property& property) const;

private:
	std::map<String, PropertyParser*> mPropertyParsers;
};

} // namespace duilib2

#endif // PROPERTYPARSERMANAGER_H
