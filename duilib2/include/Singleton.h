#ifndef SINGLETON_H
#define SINGLETON_H

#include <cassert>


namespace duilib2
{

template<typename T> class Singleton
{
public:
	Singleton()
	{
		assert(mSingleton == 0);
		mSingleton = static_cast<T*>(this);
	}

	~Singleton()
	{
		mSingleton = 0;
	}

	static T* getSingltonPtr()
	{
		assert(mSingleton != 0);
		return mSingleton;
	}

	static T& getSingleton()
	{
		assert(mSingleton != 0);
		return *mSingleton;
	}

private:
	Singleton& operator=(const Singleton<T>&);
	Singleton(const Singleton<T>&);

protected:
	static T* mSingleton;

};

} // duilib2

#endif // SINGLETON_H
