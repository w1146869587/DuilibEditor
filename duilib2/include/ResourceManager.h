#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <duilib2_global.h>
#include <Singleton.h>
#include <RawDataContainer.h>
#include <Archive.h>
#include <map>

namespace duilib2
{

class DUILIB2SHARED_EXPORT ResourceManager : public Singleton<ResourceManager>
{
public:
	ResourceManager();
	~ResourceManager();

	/**
	 * @brief
	 *     添加一个资源包，其中中包含图片、布局文件xml等
	 *
	 * @param name
	 *     唯一标识一个资源包的ID，大小写敏感
	 *
	 * @param type
	 *     资源包类型：
	 *     zip         zip压缩文件
	 *     filesystem  磁盘文件夹
	 *     res         嵌入应用程序内的资源
	 *
	 * @param location
	 *     资源包位置，比如zip文件的路径、filesystem文件夹的路径、嵌入资源的字符串ID
	 */
	void addResourcePackage(const String& name, const String& type, const String& location);

	/**
	 * @brief
	 *     Remove a resource package.
	 *
	 * @param name
	 *     The name of the resource package.
	 */
	void removeResourcePackage(const String& name);

	/**
	 * @brief
	 *     设置当前使用的资源包，可以实现动态换肤
	 *
	 * @param name
	 *     addResourcePackage()函数中使用的资源包ID
	 */
	void setCurrentResourcePackage(const String& name);

	/**
	 * @brief
	 *     在当前资源包中找到指定文件，获得该文件数据
	 *
	 * @param fileName
	 *     文件名，大小写不敏感
	 *
	 * @return
	 *     整个文件二进制数据
	 */
	RawDataContainerPtr getFileRawData(const String& fileName);

private:
	std::map<String, Archive*> mResourcePackages;
	std::map<String, RawDataContainerPtr> mRawDataCaches;
	String mCurrentResourcePackage;
};

}

#endif // RESOURCEMANAGER_H
