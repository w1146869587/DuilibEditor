/************************************************************************
	created:    Tue Feb 28 2006
	author:     Paul D Turner <paul@cegui.org.uk>
*************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2010 Paul D Turner & The CEGUI Development Team
 *
 *   Permission is hereby granted, free of charge, to any person obtaining
 *   a copy of this software and associated documentation files (the
 *   "Software"), to deal in the Software without restriction, including
 *   without limitation the rights to use, copy, modify, merge, publish,
 *   distribute, sublicense, and/or sell copies of the Software, and to
 *   permit persons to whom the Software is furnished to do so, subject to
 *   the following conditions:
 *
 *   The above copyright notice and this permission notice shall be
 *   included in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 ***************************************************************************/

#ifndef EVENT_H
#define EVENT_H

#include <duilib2_global.h>
#include <vector>
#include <boost/function.hpp>
#include <EventArgs.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Event
{
public:
	Event(const String& name);
	~Event();

	typedef boost::function<bool (const EventArgs& args)> Subscriber;

	/**
	 * @brief
	 *     Get the name of the event.
	 *
	 * @return
	 *     The name of the event.
	 */
	String getName() const;

	/**
	 * @brief
	 *     Subscribe a event handler.
	 *
	 * @param subscriber
	 *     Event handler, it is a boost::function
	 */
	void subscribe(const Subscriber& subscriber);

	/**
	 * @brief
	 *     Fire the event, the subscriber(event handler) will be called
	 *
	 * @param args
	 *     The arguments that will be passing in the subscriber.
	 */
	void fire(const EventArgs& args);

private:
	std::vector<Subscriber> mSubscribers;
	String mName;
};

} // namespace duilib2

#endif // EVENT_H
