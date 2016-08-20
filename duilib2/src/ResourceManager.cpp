#include <ResourceManager.h>

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

	// 每种类型的文档对应一个 Archive 子类
	// 比如 ZipArchive FileSystemArchive Win32ResArchive QtResArchive
	// ResourceManager 保存一个资源列表
	// name | Archive*
	// 1. 打开文件获得rawdata  archive->getFileRawData(fileName)
	// 2. 获得一张图片资源      archive->getImage(fileName) : Image
	// Resource
	// |- Image  包含图片数据
	//
}

void ResourceManager::setCurrentResourcePackage(const String& name)
{

}

RawDataContainer ResourceManager::getFileRawData(const String& fileName)
{
	// ...
	return RawDataContainer();
}

}
