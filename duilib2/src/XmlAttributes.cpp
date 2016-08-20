/***********************************************************************
	created:    Sat Mar 12 2005
	author:     Paul D Turner
*************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2006 Paul D Turner & The CEGUI Development Team
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

#include <XmlAttributes.h>
#include <cassert>

namespace duilib2
{

XmlAttributes::XmlAttributes()
{

}

XmlAttributes::~XmlAttributes()
{

}

void XmlAttributes::add(const String& name, const String& value)
{
	mAttributes[name] = value;
}

void XmlAttributes::remove(const String& name)
{
	AttributeMap::iterator pos = mAttributes.find(name);
	if (pos != mAttributes.end())
		mAttributes.erase(pos);
}

bool XmlAttributes::exists(const String& name) const
{
	return mAttributes.find(name) != mAttributes.end();
}

int XmlAttributes::getCount() const
{
	return mAttributes.size();
}

const String& XmlAttributes::getName(int index) const
{
	if (index < 0 || index >= mAttributes.size())
		assert(false && "The index is out of range : XmlAttributes::getName(int index)");

	AttributeMap::const_iterator iter = mAttributes.begin();
	std::advance(iter, index);

	return iter->first;
}

const String& XmlAttributes::getValue(int index) const
{
	if (index < 0 || index >= mAttributes.size())
		assert(false && "The index is out of range : XmlAttributes::getName(int index)");

	AttributeMap::const_iterator iter = mAttributes.begin();
	std::advance(iter, index);

	return iter->second;
}

const String& XmlAttributes::getValue(const String& name) const
{
	AttributeMap::const_iterator pos = mAttributes.find(name);
	if (pos != mAttributes.end())
		return pos->second;

	return String();
}

} // namespace duilib2
