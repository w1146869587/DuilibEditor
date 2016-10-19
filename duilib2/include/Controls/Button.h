#ifndef BUTTON_H
#define BUTTON_H

#include <duilib2_global.h>
#include <Controls/Label.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Button : public Label
{
public:
	Button(const String& name);
	virtual ~Button();
};

} // namespace duilib2


#endif  // BUTTON_H
