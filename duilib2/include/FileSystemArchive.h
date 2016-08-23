#ifndef FILESYSTEMARCHIVE_H
#define FILESYSTEMARCHIVE_H

#include <Archive.h>
#include <ArchiveFactory.h>

namespace duilib2
{

class FileSystemArchive : public Archive
{
public:
	FileSystemArchive(const String& name, const String& archType);
	virtual ~FileSystemArchive();

	/// @copydoc Archive::load
	virtual void load();

	/// @copydoc Archive::unload
	virtual void unload();

	/// @copydoc Archive::open
	virtual RawDataContainerPtr open(const String& fileName);
};

class FileSystemArchiveFactory : public ArchiveFactory
{
public:
	FileSystemArchiveFactory();
	virtual ~FileSystemArchiveFactory();

	/// @copydoc ArchiveFactory::getType
	virtual const String& getType() const;

	/// @copydoc ArchiveFactory::createInstance
	virtual Archive* createInstance(const String& name);

	/// @copydoc ArchiveFactory::destroyInstance
	virtual void destroyInstance(Archive* archive);
};

}

#endif // FILESYSTEMARCHIVE_H
