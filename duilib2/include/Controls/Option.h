#ifndef OPTION_H
#define OPTION_H

#include <duilib2_global.h>
#include <Controls/Button.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Option : public Button
{
public:
	Option(const String& name);
	virtual ~Option();
};

} // namespace duilib2


#endif  // OPTION_H
