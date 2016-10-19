#ifndef VERTICALLAYOUT_H
#define VERTICALLAYOUT_H

#include <duilib2_global.h>
#include <Controls/Container.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT VerticalLayout : public Container
{
public:
	VerticalLayout(const String& name);
	virtual ~VerticalLayout();
};

} // namespace duilib2


#endif  // VERTICALLAYOUT_H
