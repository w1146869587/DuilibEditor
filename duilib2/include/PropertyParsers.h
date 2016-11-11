#ifndef PROPERTYPARSERS_H
#define PROPERTYPARSERS_H

#include <duilib2_global.h>
#include <Property.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT PropertyParser
{
public:
	/**
	 * @brief
	 *     Parse the property's string value to concrete value.
	 *
	 * @param property
	 *     Property to be parsed.
	 */
	virtual void parse(Property& property) const;
};

class DUILIB2SHARED_EXPORT SizePropertyParser : public PropertyParser
{
public:
	/// @copydoc PropertyParser::parse
	virtual void parse(Property& property) const;
};

class DUILIB2SHARED_EXPORT RectPropertyParser : public PropertyParser
{
public:
	/// @copydoc PropertyParser::parse
	virtual void parse(Property& property) const;
};

class DUILIB2SHARED_EXPORT BytePropertyParser : public PropertyParser
{
public:
	/// @copydoc PropertyParser::parse
	virtual void parse(Property& property) const;
};

class DUILIB2SHARED_EXPORT BoolPropertyParser : public PropertyParser
{
public:
	/// @copydoc PropertyParser::parse
	virtual void parse(Property& property) const;
};

class DUILIB2SHARED_EXPORT ColorPropertyParser : public PropertyParser
{
public:
	/// @copydoc PropertyParser::parse
	virtual void parse(Property& property) const;
};

class DUILIB2SHARED_EXPORT ImagePropertyParser : public PropertyParser
{
public:
	/// @copydoc PropertyParser::parse
	virtual void parse(Property& property) const;
};

} // namespace duilib2

#endif // PROPERTYPARSERS
