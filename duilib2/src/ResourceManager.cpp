#include <ResourceManager.h>
#include <ArchiveManager.h>
#include <Exception.h>

namespace duilib2
{

ResourceManager* Singleton<ResourceManager>::mSingleton = NULL;

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{

}

void ResourceManager::addResourcePackage(const String& name, const String& type, const String& location)
{
	if (name.isEmpty())
	{
		DUILIB2_EXCEPT(Exception::ERR_INVALIDPARAMS,
							 "\'name\' can't be empty", "ResourceManager::addResourcePackage");
	}

	std::map<String, Archive*>::const_iterator pos = mResourcePackages.find(name);
	if (pos != mResourcePackages.end())
	{
		DUILIB2_EXCEPT(Exception::ERR_DUPLICATE_ITEM,
							 "Resource package named" + name + "is already exists",
							 "ResourceManager::addResourcePackage");
	}

	Archive* archive = ArchiveManager::getSingleton().load(location, type);
	mResourcePackages[name] = archive;
}

void ResourceManager::setCurrentResourcePackage(const String& name)
{
	std::map<String, Archive*>::const_iterator pos = mResourcePackages.find(name);
	if (pos == mResourcePackages.end())
	{
		DUILIB2_EXCEPT(Exception::ERR_ITEM_NOT_FOUND,
							 "Resource package named" + name + "is not exists",
							 "ResourceManager::setCurrentResourcePackage");
	}

	mCurrentResourcePackage = name;
}

RawDataContainerPtr ResourceManager::getFileRawData(const String& fileName)
{
	std::map<String, Archive*>::const_iterator pos = mResourcePackages.find(mCurrentResourcePackage);
	if (pos == mResourcePackages.end())
	{
		DUILIB2_EXCEPT(Exception::ERR_ITEM_NOT_FOUND,
							 "Current resource package named" + mCurrentResourcePackage + "is not exists",
							 "ResourceManager::getFileRawData");
	}

	return pos->second->open(fileName);
}

}
