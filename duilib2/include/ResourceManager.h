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
	 *     Add a resource package that contains images, layout xml etc..
	 *
	 * @param name
	 *     ID name, case sensitive.
	 *
	 * @param type
	 *     For example:
	 *     zip         .zip file
	 *     filesystem
	 *     res         Resources that embedded in application.
	 *
	 * @param location
	 *     Location of the resource package.
	 *     If type is 'res', the location is the resource ID.
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
	 * @brief setCurrentResourcePackage
	 *
	 * @param name
	 *     The ID name of the resource package.
	 */
	void setCurrentResourcePackage(const String& name);

	/**
	 * @brief
	 *     Get the raw data of the file in resource package.
	 *
	 * @param fileName
	 *     File name, case sensitive.
	 *
	 * @return
	 *     Raw data of the file (binary data).
	 */
	RawDataContainerPtr getFileRawData(const String& fileName);

	//Image getImage(const String& fileName)

private:
	std::map<String, Archive*> mResourcePackages;
	std::map<String, RawDataContainerPtr> mRawDataCaches;
	String mCurrentResourcePackage;
};

}

#endif // RESOURCEMANAGER_H
