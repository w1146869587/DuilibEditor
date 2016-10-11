#include <EventArgs.h>

namespace duilib2
{

EventArgs::EventArgs()
{

}

EventArgs::~EventArgs()
{

}

MouseEventArgs::MouseEventArgs()
{

}

MouseEventArgs::~MouseEventArgs()
{

}

Point MouseEventArgs::getScreenPos() const
{
	return mScreenPos;
}

} // namespace duilib2
