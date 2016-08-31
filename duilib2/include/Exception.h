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

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <duilib2_global.h>
#include <exception>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Exception : public std::exception
{
public:
	enum ExceptionCodes
	{
		ERR_CANNOT_WRITE_TO_FILE,
		ERR_INVALID_STATE,
		ERR_INVALIDPARAMS,
		ERR_DUPLICATE_ITEM,
		ERR_ITEM_NOT_FOUND,
		ERR_FILE_NOT_FOUND,
		ERR_INTERNAL_ERROR,
		ERR_RT_ASSERTION_FAILED,
		ERR_NOT_IMPLEMENTED
	};

	Exception(int number, const String& description, const String& source);
	Exception(int number, const String& description, const String& source,
			  const char* type, const char* file, int line);
	~Exception();

	/// Returns a string with the full description of this error
	virtual const String& getFullDescription() const;

	/// Gets the error code
	virtual int getNumber() const;

	/// Gets the source function
	virtual const String& getSource() const;

	/// Gets source file name
	virtual const String& getFile() const;

	/// Gets line number
	virtual int getLine() const;

	/// Gets description
	virtual const String& getDescription() const;

	/// Override std::exception::what
	virtual const char* what() const;

private:
	int mLine;
	int mNumber;
	String mTypeName;
	String mDescription;
	String mSource;
	String mFile;
	mutable String mFullDesc;
};

template<int num>
struct ExceptionCodeType
{
	ExceptionCodeType() : number(num) {}
	int number;
	//enum { number = num };
};

class DUILIB2SHARED_EXPORT UnimplementedException : public Exception
{
public:
	UnimplementedException(int number, const String& description, const String& source,
						   const char* file, int line)
		: Exception(number, description, source, "UnimplementedException", file, line) {}
};

class DUILIB2SHARED_EXPORT FileNotFoundException : public Exception
{
public:
	FileNotFoundException(int number, const String& description, const String& source,
						   const char* file, int line)
		: Exception(number, description, source, "FileNotFoundException", file, line) {}
};

class DUILIB2SHARED_EXPORT IOException : public Exception
{
public:
	IOException(int number, const String& description, const String& source,
						   const char* file, int line)
		: Exception(number, description, source, "IOException", file, line) {}
};

class DUILIB2SHARED_EXPORT InvalidStateException : public Exception
{
public:
	InvalidStateException(int number, const String& description, const String& source,
						   const char* file, int line)
		: Exception(number, description, source, "InvalidStateException", file, line) {}
};

class DUILIB2SHARED_EXPORT InvalidParametersException : public Exception
{
public:
	InvalidParametersException(int number, const String& description, const String& source,
						   const char* file, int line)
		: Exception(number, description, source, "InvalidParametersException", file, line) {}
};

class DUILIB2SHARED_EXPORT ItemIdentityException : public Exception
{
public:
	ItemIdentityException(int number, const String& description, const String& source,
						   const char* file, int line)
		: Exception(number, description, source, "ItemIdentityException", file, line) {}
};

class DUILIB2SHARED_EXPORT InternalErrorException : public Exception
{
public:
	InternalErrorException(int number, const String& description, const String& source,
						   const char* file, int line)
		: Exception(number, description, source, "InternalErrorException", file, line) {}
};

class DUILIB2SHARED_EXPORT RuntimeAssertionException : public Exception
{
public:
	RuntimeAssertionException(int number, const String& description, const String& source,
						   const char* file, int line)
		: Exception(number, description, source, "RuntimeAssertionException", file, line) {}
};

class ExceptionFactory
{
public:
	static UnimplementedException create(
			ExceptionCodeType<Exception::ERR_NOT_IMPLEMENTED> code,
			const String& desc,
			const String& src, const char* file, int line)
	{
		return UnimplementedException(code.number, desc, src, file, line);
	}

	static FileNotFoundException create(
			ExceptionCodeType<Exception::ERR_FILE_NOT_FOUND> code,
			const String& desc,
			const String& src, const char* file, int line)
	{
		return FileNotFoundException(code.number, desc, src, file, line);
	}

	static IOException create(
			ExceptionCodeType<Exception::ERR_CANNOT_WRITE_TO_FILE> code,
			const String& desc,
			const String& src, const char* file, int line)
	{
		return IOException(code.number, desc, src, file, line);
	}

	static InvalidStateException create(
			ExceptionCodeType<Exception::ERR_INVALID_STATE> code,
			const String& desc,
			const String& src, const char* file, int line)
	{
		return InvalidStateException(code.number, desc, src, file, line);
	}

	static InvalidParametersException create(
			ExceptionCodeType<Exception::ERR_INVALIDPARAMS> code,
			const String& desc,
			const String& src, const char* file, int line)
	{
		return InvalidParametersException(code.number, desc, src, file, line);
	}

	static ItemIdentityException create(
			ExceptionCodeType<Exception::ERR_ITEM_NOT_FOUND> code,
			const String& desc,
			const String& src, const char* file, int line)
	{
		return ItemIdentityException(code.number, desc, src, file, line);
	}

	static ItemIdentityException create(
			ExceptionCodeType<Exception::ERR_DUPLICATE_ITEM> code,
			const String& desc,
			const String& src, const char* file, int line)
	{
		return ItemIdentityException(code.number, desc, src, file, line);
	}

	static InternalErrorException create(
			ExceptionCodeType<Exception::ERR_INTERNAL_ERROR> code,
			const String& desc,
			const String& src, const char* file, int line)
	{
		return InternalErrorException(code.number, desc, src, file, line);
	}

	static RuntimeAssertionException create(
			ExceptionCodeType<Exception::ERR_RT_ASSERTION_FAILED> code,
			const String& desc,
			const String& src, const char* file, int line)
	{
		return RuntimeAssertionException(code.number, desc, src, file, line);
	}
};

#ifndef DUILIB2_EXCEPT
#define DUILIB2_EXCEPT(num, desc, src) throw duilib2::ExceptionFactory::create( \
	duilib2::ExceptionCodeType<num>(), desc, src, __FILE__, __LINE__);

#endif

}  // namespace duilib2

#endif // EXCEPTION_H
