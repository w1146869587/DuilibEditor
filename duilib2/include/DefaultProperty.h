#ifndef DEFAULTPROPERTY_H
#define DEFAULTPROPERTY_H

#include <duilib2_global.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT DefaultProperty
{
public:
	DefaultProperty();
	~DefaultProperty();

	/**
	 * @brief setProperty
	 * @param name
	 * @param value
	 */
	void setProperty(const String& name, const String& value);
};

} // namespace duilib2


#endif // DEFAULTPROPERTY_H
