#include <EventSet.h>

namespace duilib2
{

EventSet::EventSet()
{

}

EventSet::~EventSet()
{
	std::map<String, Event*>::iterator iter;
	for (iter = mEvents.begin(); iter != mEvents.end(); ++iter)
		delete iter->second;
}

void EventSet::subscribeEvent(const String& name, const Event::Subscriber& subscriber)
{
	getEventObject(name, true)->subscribe(subscriber);
}

void EventSet::fireEvent(const String& name, const EventArgs& args)
{
	Event* event = getEventObject(name);
	if (event)
		event->fire(args);
}

Event* EventSet::getEventObject(const String& name, bool autoAdd)
{
	std::map<String, Event*>::iterator pos = mEvents.find(name);
	if (pos != mEvents.end())
		return pos->second;

	Event* event = NULL;
	if (autoAdd)
	{
		event = new Event(name);
		mEvents[name] = event;
	}

	return event;
}

} // namespace duilib2
