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

#ifndef RAWDATACONTAINER_H
#define RAWDATACONTAINER_H

#include <duilib2_global.h>

namespace duilib2
{

/**
 * @brief Class used as the databuffer for loading files
 */
class DUILIB2SHARED_EXPORT RawDataContainer
{
public:
	RawDataContainer();
	~RawDataContainer();

	/**
	 * @brief
	 *     Set a pointer to the external data.
	 *
	 * @param data
	 *     Pointer to the data buffer.
	 */
	void setData(unsigned char* data);

	/**
	 * @brief
	 *     Return a pointer to the external data.
	 *
	 * @return
	 *     Pointer to the data buffer.
	 */
	unsigned char* getData();
	const unsigned char* getData() const;

	/**
	 * @brief
	 *     Set the size of the external data.
	 *
	 * @param size
	 *     Contain the size of the external data.
	 */
	void setSize(int size);

	/**
	 * @brief
	 *     Get the size of the external data.
	 *
	 * @return
	 *     The size of the external data.
	 */
	int getSize() const;

	/**
	 * @brief Release supplied data.
	 */
	void release();

private:
	unsigned char* mData;
	int mSize;
};

}

#endif // RAWDATACONTAINER_H
