#ifndef CONTROL_H
#define CONTROL_H

#include <duilib2_global.h>
#include <Window.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Control : public Window
{
public:
	Control(const String& name);
	virtual ~Control();
};

} // namespace duilib2


#endif  // CONTROL_H
