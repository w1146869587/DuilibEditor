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
		throw Exception("\'name\' can't be empty.");
	}

	std::map<String, Archive*>::const_iterator pos = mResourcePackages.find(name);
	if (pos == mResourcePackages.end())
	{
		throw Exception("Resource Package named" + name + "is already exists");
	}

	Archive* archive = ArchiveManager::getSingleton().load(location, type);
	mResourcePackages[name] = archive;
}

void ResourceManager::setCurrentResourcePackage(const String& name)
{
	std::map<String, Archive*>::const_iterator pos = mResourcePackages.find(name);
	if (pos == mResourcePackages.end())
	{
		throw Exception("Resource Package named" + name + "is not exists");
	}

	mCurrentResourcePackage = name;
}

RawDataContainerPtr ResourceManager::getFileRawData(const String& fileName)
{
	std::map<String, Archive*>::const_iterator pos = mResourcePackages.find(fileName);
	if (pos == mResourcePackages.end())
	{
		throw Exception("Current resource Package named" + mCurrentResourcePackage + "is not exists");
	}

	return pos->second->open(fileName);
}

}
