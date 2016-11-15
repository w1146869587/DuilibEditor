#ifndef FONT_H
#define FONT_H

#include <duilib2_global.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Font
{
public:
	Font();
	~Font();

	/**
	 * @brief setProperty
	 * @param name
	 * @param value
	 */
	void setProperty(const String& name, const String& value);
};

} // namespace duilib2

#endif // FONT_H
