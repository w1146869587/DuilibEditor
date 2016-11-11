#include <PropertyParsers.h>
#include <PropertyTypes.h>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <Exception.h>

namespace duilib2
{

void PropertyParser::parse(Property& property) const
{
	property.setAnyValue(property.getValue());
}

void SizePropertyParser::parse(Property& property) const
{
	// e.g. "300, 400"
	std::string value = property.getValue().toLocal8Bit();

	std::vector<std::string> splitVec;
	boost::split(splitVec, value, boost::is_any_of(","), boost::token_compress_on);

	if (splitVec.size() != 2)
	{
		DUILIB2_EXCEPT(Exception::ERR_INTERNAL_ERROR,
					   "Property value's format is wrong", "SizePropertyParser::parse");
	}

	try
	{
		Size size;
		size.mWidth = boost::lexical_cast<int>(boost::trim_copy(splitVec[0]));
		size.mHeight = boost::lexical_cast<int>(boost::trim_copy(splitVec[1]));
		property.setAnyValue(size);
	}
	catch (boost::bad_lexical_cast&)
	{
		DUILIB2_EXCEPT(Exception::ERR_INTERNAL_ERROR,
					   "Property value's format is wrong", "SizePropertyParser::parse");
	}
}

void RectPropertyParser::parse(Property& property) const
{
	// e.g. "0, 0, 300, 400"
	std::string value = property.getValue().toLocal8Bit();

	std::vector<std::string> splitVec;
	boost::split(splitVec, value, boost::is_any_of(","), boost::token_compress_on);

	if (splitVec.size() != 4)
	{
		DUILIB2_EXCEPT(Exception::ERR_INTERNAL_ERROR,
					   "Property value's format is wrong", "RectPropertyParser::parse");
	}

	try
	{
		Rect rect;
		rect.mLeft = boost::lexical_cast<int>(boost::trim_copy(splitVec[0]));
		rect.mTop = boost::lexical_cast<int>(boost::trim_copy(splitVec[1]));
		rect.mRight = boost::lexical_cast<int>(boost::trim_copy(splitVec[2]));
		rect.mBottom = boost::lexical_cast<int>(boost::trim_copy(splitVec[3]));
		property.setAnyValue(rect);
	}
	catch (boost::bad_lexical_cast&)
	{
		DUILIB2_EXCEPT(Exception::ERR_INTERNAL_ERROR,
					   "Property value's format is wrong", "RectPropertyParser::parse");
	}
}

void BytePropertyParser::parse(Property& property) const
{
	// e.g. "255"
	std::string value = property.getValue().toLocal8Bit();
	boost::trim(value);

	try
	{
		Byte byte = boost::lexical_cast<int>(value);
		property.setAnyValue(byte);
	}
	catch (boost::bad_lexical_cast&)
	{
		DUILIB2_EXCEPT(Exception::ERR_INTERNAL_ERROR,
					   "Property value's format is wrong", "BytePropertyParser::parse");
	}
}

void BoolPropertyParser::parse(Property& property) const
{
	// e.g. "true" "false"
	std::string value = property.getValue().toLocal8Bit();
	boost::trim(value);
	boost::to_lower(value);

	Bool realValue;
	if (value == "true")
		realValue = true;
	else
		realValue = false;

	property.setAnyValue(realValue);
}

void ColorPropertyParser::parse(Property& property) const
{
	// e.g. "0xffd3215f" "ffd3215f" "d3215f"
	// 支持的格式 0x可有可无，开头的alpha值可有可无
	std::string value = property.getValue().toLocal8Bit();
	boost::trim(value);
	boost::to_lower(value);

	if (boost::starts_with(value, "0x"))
		value = value.substr(2);

	if (value.size() <  5)
	{
		DUILIB2_EXCEPT(Exception::ERR_INTERNAL_ERROR,
					   "Property value's format is wrong", "ColorPropertyParser::parse");
	}


	if (value.size() % 2 == 1)
		value = '0' + value;

	std::string red, green, blue, alpha("ff");
	if (value.size() == 8)
	{
		alpha = value.substr(0, 2);
		value = value.substr(2);
	}

	red = value.substr(0, 2);
	green = value.substr(2, 2);
	blue = value.substr(4, 2);

	try
	{
		Color color;
		color.mAlpha = std::stoi(alpha, 0, 16); // C++11
		color.mRed = std::stoi(red, 0, 16);
		color.mGreen = std::stoi(green, 0, 16);
		color.mBlue = std::stoi(blue, 0, 16);
		property.setAnyValue(color);
	}
	catch (...)
	{
		DUILIB2_EXCEPT(Exception::ERR_INTERNAL_ERROR,
					   "Property value's format is wrong", "ColorPropertyParser::parse");
	}
}

void ImagePropertyParser::parse(Property& property) const
{
	// ...
}

} // namespace duilib2
