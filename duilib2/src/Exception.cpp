/*
-----------------------------------------------------------------------------
This source file is part of OGRE
(Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/

Copyright (c) 2000-2013 Torus Knot Software Ltd

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/

#include <Exception.h>
#include <sstream>

namespace duilib2
{

Exception::Exception(int number, const String& description, const String& source)
	: mLine(0)
	, mNumber(number)
	, mDescription(description)
	, mSource(source)
{

}

Exception::Exception(int number, const String& description, const String& source,
		  const char* type, const char* file, int line)
	: mLine(line)
	, mNumber(number)
	, mTypeName(type)
	, mDescription(description)
	, mSource(source)
	, mFile(file)
{

}

Exception::~Exception()
{

}

const String& Exception::getFullDescription() const
{
	if (mFullDesc.isEmpty())
	{
		std::ostringstream desc;
		desc << "EXCEPTION(" << mNumber << ":" << mTypeName.toLocal8Bit().data() << "): "
			   << mDescription.toLocal8Bit().data()
			   << " in " << mSource.toLocal8Bit().data();

		if (mLine > 0)
		{
			desc << " at " << mFile.toLocal8Bit().data() << " (line " << mLine << ")";
		}

		mFullDesc.fromLocal8Bit(desc.str().c_str());
	}

	return mFullDesc;
}

int Exception::getNumber() const
{
	return mNumber;
}

const String& Exception::getSource() const
{
	return mSource;
}

const String& Exception::getFile() const
{
	return mFile;
}

int Exception::getLine() const
{
	return mLine;
}

const String& Exception::getDescription() const
{
	return mDescription;
}

const char* Exception::what() const
{
	return getFullDescription().toLocal8Bit().data();
}

}
