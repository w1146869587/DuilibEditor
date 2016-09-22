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

#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <duilib2_global.h>
#include <XmlHandler.h>
#include <RawDataContainer.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT XmlParser
{
public:
	XmlParser() {}
	virtual ~XmlParser() {}

	/**
	 * @brief initialise
	 */
	virtual void initialise() {}

	/**
	 * @brief cleanup
	 */
	virtual void cleanup() {}

	/**
	 * @brief
	 *     Get the identifier string of this xml parser.
	 *
	 * @return
	 *     The identifier string.
	 */
	virtual String getIdentifierString() = 0;

	/**
	 * @brief
	 *     Parsing xml from rawdata.
	 *
	 * @param handler
	 *     The handler for parsing xml.
	 *
	 * @param source
	 *     The rawdata(file text stream).
	 */
	virtual void parseXml(XmlHandler& handler, const RawDataContainer& source) = 0;

	/**
	 * @brief
	 *     Parsing xml from file.
	 *
	 * @param handler
	 *     The handler for parsing xml.
	 *
	 * @param fileName
	 *     The file name.
	 */
	virtual void parseXmlFile(XmlHandler& handler, const String& fileName) = 0;

	/**
	 * @brief
	 *     Parsing xml from string, similar to \a parseXml().
	 *
	 * @param handler
	 *     The handler for parsing xml.
	 *
	 * @param source
	 *     The file text string.
	 */
	virtual void parseXmlString(XmlHandler& handler, const String& source) = 0;
};

}

#endif // XMLPARSER_H
