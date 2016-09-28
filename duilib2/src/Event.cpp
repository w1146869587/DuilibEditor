#include <Event.h>

namespace duilib2
{

Event::Event(const String& name)
	: mName(name)
{

}

Event::~Event()
{

}

String Event::getName() const
{
	return mName;
}

void Event::subscribe(const Subscriber& subscriber)
{
	mSubscribers.push_back(subscriber);
}

void Event::fire(const EventArgs& args)
{
	for (int i = 0; i < (int)mSubscribers.size(); ++i)
	{
		mSubscribers[i](args);
	}
}

} // namespace duilib2
