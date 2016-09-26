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

} // namespace duilib2
