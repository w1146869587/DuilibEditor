#ifndef CONTAINER_H
#define CONTAINER_H

#include <duilib2_global.h>
#include <Controls/Control.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Container : public Control
{
public:
	Container(const String& name);
	virtual ~Container();
};

} // namespace duilib2


#endif  // CONTAINER_H
