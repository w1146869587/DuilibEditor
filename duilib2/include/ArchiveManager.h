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

#ifndef ARCHIVEMANAGER_H
#define ARCHIVEMANAGER_H

#include <duilib2_global.h>
#include <Singleton.h>
#include <Archive.h>
#include <ArchiveFactory.h>
#include <map>

namespace duilib2
{

class ArchiveManager : public Singleton<ArchiveManager>
{
public:
	ArchiveManager();
	~ArchiveManager();

	/**
	 * @brief
	 *     Open an archive for file reading
	 *
	 * @param fileName
	 *     The file name that will be opened.
	 *
	 * @param archiveType
	 *     The type of archive that this is. For example: "Zip".
	 *
	 * @return
	 *     If the function succeeds, a valid pointer to an Archive
	 *     object is returned.
	 * @par
	 *     If the function fails, an exception is thrown.
	 */
	Archive* load(const String& fileName, const String& archiveType);

	/**
	 * @brief
	 *     Unloads an archive
	 *
	 * @param archive
	 *     The archive that will be unloaded.
	 */
	void unload(Archive* archive);

	/**
	 * @brief
	 *     Unloads an archive by name.
	 *
	 * @param fileName
	 */
	void unload(const String& fileName);

	/**
	 * @brief
	 *     Adds a new ArchiveFactory to the list of available factories.
	 *
	 * @param factory
	 */
	void addArchiveFactory(ArchiveFactory* factory);

private:
	typedef std::map<String, ArchiveFactory*> ArchiveFactoryMap;
	typedef std::map<String, Archive*> ArchiveMap;

	ArchiveFactoryMap mArchiveFactories;
	ArchiveMap        mArchives;
};

}


#endif // ARCHIVEMANAGER_H
