#ifndef LABEL_H
#define LABEL_H

#include <duilib2_global.h>
#include <Controls/Control.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Label : public Control
{
public:
	Label(const String& name);
	virtual ~Label();
};

} // namespace duilib2


#endif  // LABEL_H
