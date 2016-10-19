#ifndef HORIZONTALLAYOUT_H
#define HORIZONTALLAYOUT_H

#include <duilib2_global.h>
#include <Controls/Container.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT HorizontalLayout : public Container
{
public:
	HorizontalLayout(const String& name);
	virtual ~HorizontalLayout();
};

} // namespace duilib2


#endif  // HORIZONTALLAYOUT_H
