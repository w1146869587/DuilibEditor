#include <PropertyParsers.h>
#include <PropertyTypes.h>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <Exception.h>

namespace duilib2
{

void SizePropertyParser::parse(Property& property) const
{
	// e.g. "300, 400"
	std::string value = property.getValue().toLocal8Bit();
	std::vector<std::string> splitVec;
	boost::split(splitVec, value, boost::is_any_of(","), boost::token_compress_on);
	if (splitVec.size() != 2)
	{
		DUILIB2_EXCEPT(Exception::ERR_INTERNAL_ERROR,
					   "Property's format is wrong", "SizePropertyParser::parse");
	}

	Size size;
	size.mWidth = boost::lexical_cast<int>(boost::trim_copy(splitVec[0]));
	size.mHeight = boost::lexical_cast<int>(boost::trim_copy(splitVec[1]));
	property.setAnyValue(size);
}

void RectPropertyParser::parse(Property& property) const
{
}

void BytePropertyParser::parse(Property& property) const
{
}

void BoolPropertyParser::parse(Property& property) const
{
}

void ColorPropertyParser::parse(Property& property) const
{
}

} // namespace duilib2
