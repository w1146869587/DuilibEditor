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
							 "Resource package named " + name + " is already exists",
							 "ResourceManager::addResourcePackage");
	}

	Archive* archive = ArchiveManager::getSingleton().load(location, type);
	mResourcePackages[name] = archive;
}

void ResourceManager::removeResourcePackage(const String& name)
{
	if (name.isEmpty())
	{
		DUILIB2_EXCEPT(Exception::ERR_INVALIDPARAMS,
							 "\'name\' can't be empty", "ResourceManager::removeResourcePackage");
	}

	mResourcePackages.erase(name);
	if (name == mCurrentResourcePackage)
		mCurrentResourcePackage.clear();
}

void ResourceManager::setCurrentResourcePackage(const String& name)
{
	std::map<String, Archive*>::const_iterator pos = mResourcePackages.find(name);
	if (pos == mResourcePackages.end())
	{
		DUILIB2_EXCEPT(Exception::ERR_ITEM_NOT_FOUND,
							 "Resource package named " + name + " is not exists",
							 "ResourceManager::setCurrentResourcePackage");
	}

	mCurrentResourcePackage = name;
	mRawDataCaches.clear();
}

RawDataContainerPtr ResourceManager::getFileRawData(const String& fileName)
{
	if (fileName.isEmpty())
	{
		DUILIB2_EXCEPT(Exception::ERR_INVALIDPARAMS,
							 "\'fileName\' can't be empty", "ResourceManager::getFileRawData");
	}

	std::map<String, RawDataContainerPtr>::const_iterator posCache = mRawDataCaches.find(fileName);
	if (posCache != mRawDataCaches.end())
		return posCache->second;

	std::map<String, Archive*>::const_iterator pos = mResourcePackages.find(mCurrentResourcePackage);
	if (pos == mResourcePackages.end())
	{
		DUILIB2_EXCEPT(Exception::ERR_ITEM_NOT_FOUND,
					   "Current resource package named " + mCurrentResourcePackage + " is not exists",
					   "ResourceManager::getFileRawData");
	}

	RawDataContainerPtr rawDataPtr = pos->second->open(fileName);
	mRawDataCaches[fileName] = rawDataPtr;

	return rawDataPtr;
}

QImage ResourceManager::getImage(const String& fileName)
{
	RawDataContainerPtr rawData = getFileRawData(fileName);
	QImage image;
	if (!image.loadFromData(rawData->getData(), rawData->getSize()))
	{
		DUILIB2_EXCEPT(Exception::ERR_INTERNAL_ERROR,
					   "Can\'t load image: " + fileName,
					   "ResourceManager::getFileRawData");
	}

	return image;
}

} // namespace duilib2
