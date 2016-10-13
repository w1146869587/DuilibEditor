#include <EventArgs.h>

namespace duilib2
{

EventArgs::EventArgs()
{

}

EventArgs::~EventArgs()
{

}

MouseEventArgs::MouseEventArgs(const Point& pos, MouseButton button)
	: mScreenPos(pos)
	, mButton(button)
{

}

MouseEventArgs::~MouseEventArgs()
{

}

} // namespace duilib2
