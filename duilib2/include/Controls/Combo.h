#ifndef COMBO_H
#define COMBO_H

#include <duilib2_global.h>
#include <Controls/Container.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Combo : public Container
{
public:
	Combo(const String& name);
	virtual ~Combo();
};

} // namespace duilib2


#endif  // COMBO_H
