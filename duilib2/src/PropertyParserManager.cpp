#include <PropertyParserManager.h>
#include <Exception.h>
#include <PropertyParsers.h>
#include <utility>

namespace duilib2
{

PropertyParserManager* Singleton<PropertyParserManager>::mSingleton = NULL;

PropertyParserManager::PropertyParserManager()
{
	mPropertyParsers.insert(std::make_pair(String("Size"), new SizePropertyParser));
	mPropertyParsers.insert(std::make_pair(String("Rect"), new RectPropertyParser));
	mPropertyParsers.insert(std::make_pair(String("Byte"), new BytePropertyParser));
	mPropertyParsers.insert(std::make_pair(String("Bool"), new BoolPropertyParser));
	mPropertyParsers.insert(std::make_pair(String("Color"), new ColorPropertyParser));
}

PropertyParserManager::~PropertyParserManager()
{
	std::map<String, PropertyParser*>::iterator iter;
	for (iter = mPropertyParsers.begin(); iter != mPropertyParsers.end(); ++iter)
		delete iter->second;
}

const PropertyParser* PropertyParserManager::getParser(const String& type) const
{
	std::map<String, PropertyParser*>::const_iterator pos = mPropertyParsers.find(type);
	if (pos == mPropertyParsers.end())
		return NULL;

	return pos->second;
}

Property& PropertyParserManager::parse(Property& property) const
{
	const PropertyParser* parser = getParser(property.getType());
	if (parser == NULL)
	{
		DUILIB2_EXCEPT(Exception::ERR_ITEM_NOT_FOUND,
					   "Cannot find property parser for type " + property.getType(),
					   "PropertyParserManager::parse");
	}

	parser->parse(property);
	return property;
}


} // namespace duilib2
