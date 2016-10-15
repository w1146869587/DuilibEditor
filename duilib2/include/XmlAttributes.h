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

#ifndef XMLATTRIBUTE_H
#define XMLATTRIBUTE_H

#include <duilib2_global.h>
#include <map>

namespace duilib2
{

/**
 * @brief
 *     Class representing a block of attributes associated with an XML element.
 */
class DUILIB2SHARED_EXPORT XmlAttributes
{
public:
	XmlAttributes();
	~XmlAttributes();

	/**
	 * @brief
	 *     Add an attribute to the attribute block. if the attribute value already exists,
	 *     it is replaced with the new value.
	 *
	 * @param name
	 *     String object holding the name of the attributes to be added.
	 *
	 * @param value
	 *     String object holding a string representation of the attribute value.
	 */
	void add(const String& name, const String& value);

	/**
	 * @brief
	 *     Removes an attribute from the attribute block.
	 *
	 * @param name
	 *     The name of the attribute to be removed.
	 */
	void remove(const String& name);

	/**
	 * @brief
	 *     Return whether the named attribute exists within the attribute block.
	 *
	 * @param name
	 *     The name of the attribute to be checked.
	 *
	 * @return
	 *     - true if an attribute with the name \a name is present in the attribute block.
	 *     - false if no attribute named \a name is present in the attribute block.
	 */
	bool exists(const String& name) const;

	/**
	 * @brief
	 *     Return the number of attributes in the attribute block.
	 *
	 * @return
	 *     value specifying the number of attributes in this attribute block.
	 */
	int getCount() const;

	/**
	 * @brief
	 *     Return the name of an attribute based upon its index within the attribute block.
	 *
	 * @param index
	 *     Zero based index of the attribute whos name is to be returned.
	 *
	 * @return
	 *     The name of the attribute at the requested index.
	 */
	String getName(int index) const;

	/**
	 * @brief
	 *     Return the value string of the attribute based upon its index within the attribute block.
	 *
	 * @param index
	 *     Zero based index of the attribute whos name is to be returned.
	 *
	 * @return
	 *     The name of the attribute at the requested index.
	 */
	String getValue(int index) const;

	/**
	 * @brief
	 *     Return the value string for attribute \a name.
	 *
	 * @param name
	 *     The name of the attribute whos value string is to be returned.
	 *
	 * @return
	 *     The value string for attribute \a name.
	 */
	String getValue(const String& name) const;

private:
	typedef std::map<String, String> AttributeMap;
	AttributeMap mAttributes;
};

}

#endif // XMLATTRIBUTE_H
