#ifndef EVENTARGS_H
#define EVENTARGS_H

#include <duilib2_global.h>
#include <Types.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT EventArgs
{
public:
	EventArgs();
	virtual ~EventArgs();


};

enum MouseButton
{
	MB_NONE_BUTTON,
	MB_LEFT_BUTTON,
	MB_RIGHT_BUTTON,
	MB_MID_BUTTON
};

class DUILIB2SHARED_EXPORT MouseEventArgs : public EventArgs
{
public:
	MouseEventArgs(const Point& pos, MouseButton button);
	virtual ~MouseEventArgs();

public:
	Point mScreenPos;
	MouseButton mButton;
};

} // namespace duilib2

#endif // EVENTARGS_H
