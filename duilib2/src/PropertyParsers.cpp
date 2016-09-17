#include <PropertyParsers.h>
#include <PropertyTypes.h>

namespace duilib2
{

void SizePropertyParser::parse(Property& property) const
{
	// 分析 property.getValue();
	// 设置到 property.setAnyValue<Size>(size);
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
