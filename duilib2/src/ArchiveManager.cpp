/*
-----------------------------------------------------------------------------
This source file is part of OGRE
	(Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/

Copyright (c) 2000-2014 Torus Knot Software Ltd

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

#include <ArchiveManager.h>
#include <Exception.h>

namespace duilib2
{

ArchiveManager* Singleton<ArchiveManager>::mSingleton = NULL;


ArchiveManager::ArchiveManager()
{

}

ArchiveManager::~ArchiveManager()
{
	// 释放已加载的文档资源
	for (ArchiveMap::iterator iter = mArchives.begin(); iter != mArchives.end(); ++iter)
	{
		Archive* archive = iter->second;
		// Unload
		archive->unload();
		// Find factory to destroy archive instance
		ArchiveFactoryMap::iterator iterF = mArchiveFactories.find(archive->getType());
		if (iterF == mArchiveFactories.end())
		{
			DUILIB2_EXCEPT(Exception::ERR_ITEM_NOT_FOUND,
								 "Cannot find archive factory for type" + archive->getType(),
								 "ArchiveManager::~ArchiveManager");
		}
		iterF->second->destroyInstance(archive);
	}
	mArchives.clear();

	// 删除ArchiveFactory
	for (ArchiveFactoryMap::iterator iter = mArchiveFactories.begin();
		 iter != mArchiveFactories.end(); ++iter)
	{
		delete iter->second;
	}
	mArchiveFactories.clear();
}

Archive* ArchiveManager::load(const String& fileName, const String& archiveType)
{
	ArchiveMap::iterator iter = mArchives.find(fileName);
	Archive* archive = 0;

	if (iter == mArchives.end())
	{
		ArchiveFactoryMap::iterator iterFactory = mArchiveFactories.find(archiveType);
		if (iterFactory == mArchiveFactories.end())
		{
			DUILIB2_EXCEPT(Exception::ERR_ITEM_NOT_FOUND,
								 "Cannot find an archive factory for type" + archiveType,
								 "ArchiveManager::load");
		}

		archive = iterFactory->second->createInstance(fileName);
		archive->load();
		mArchives[fileName] = archive;
	}
	else
	{
		archive = iter->second;
	}

	return archive;
}

void ArchiveManager::unload(Archive* archive)
{
	unload(archive->getName());
}

void ArchiveManager::unload(const String& fileName)
{
	ArchiveMap::iterator iter = mArchives.find(fileName);
	if (iter != mArchives.end())
	{
		iter->second->unload();

		// Find factory to destroy the archive instance
		ArchiveFactoryMap::iterator iterFactory = mArchiveFactories.find(iter->second->getType());
		if (iterFactory == mArchiveFactories.end())
		{
			DUILIB2_EXCEPT(Exception::ERR_ITEM_NOT_FOUND,
								 "Cannot find an archive factory for type" + iter->second->getType(),
								 "ArchiveManager::unload");
		}

		iterFactory->second->destroyInstance(iter->second);
		mArchives.erase(iter);
	}
}

void ArchiveManager::addArchiveFactory(ArchiveFactory* factory)
{
	mArchiveFactories[factory->getType()] = factory;
}

}
