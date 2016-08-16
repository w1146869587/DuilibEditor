#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <duilib2_global.h>
#include <Singleton.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT ResourceManager : public Singleton<ResourceManager>
{
public:
	ResourceManager();
	~ResourceManager();

	/**
	 * @brief 添加资源
	 * @param name
	 *		唯一标识一个资源的idName
	 * @param type
	 *		资源类型，比如zip、filesystem
	 * @param location
	 *		资源引用的位置，比如zip文件路径
	 */
	void addResource(const String& name, const String& type, const String& location);

	void setCurrentResource(const String& name);

private:
};

}

#endif // RESOURCEMANAGER_H
