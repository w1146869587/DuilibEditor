/***********************************************************************
	created:    21/2/2004
	author:     Paul D Turner

	purpose:    Defines class for a named collection of Event objects
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

#ifndef EVENTSET_H
#define EVENTSET_H

#include <duilib2_global.h>
#include <Event.h>
#include <map>

namespace duilib2
{

class DUILIB2SHARED_EXPORT EventSet
{
public:
	EventSet();
	virtual ~EventSet();

	/**
	 * @brief subscribeEvent
	 * @param name
	 * @param subscriber
	 */
	void subscribeEvent(const String& name, const Event::Subscriber& subscriber);

	/**
	 * @brief fireEvent
	 * @param name
	 * @param args
	 */
	void fireEvent(const String& name, const EventArgs& args);

	/**
	 * @brief getEventObject
	 * @param name
	 * @param autoAdd
	 * @return
	 */
	Event* getEventObject(const String& name, bool autoAdd = false);

private:
	std::map<String, Event*> mEvents;
};

} // namespace duilib2

#endif // EVENTSET_H
