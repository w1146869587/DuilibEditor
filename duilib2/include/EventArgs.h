#ifndef EVENTARGS_H
#define EVENTARGS_H

#include <duilib2_global.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT EventArgs
{
public:
	EventArgs();
	virtual ~EventArgs();


};

class DUILIB2SHARED_EXPORT WindowEventArgs : public EventArgs
{
public:
	WindowEventArgs();
	virtual ~WindowEventArgs();

};

} // namespace duilib2

#endif // EVENTARGS_H