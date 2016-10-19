#ifndef EDIT_H
#define EDIT_H

#include <duilib2_global.h>
#include <Controls/Label.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Edit : public Label
{
public:
	Edit(const String& name);
	virtual ~Edit();
};

} // namespace duilib2


#endif  // EDIT_H
