#include <FileSystemArchive.h>
#include <Exception.h>
#include <fstream>
#include <sstream>
#include <string>

namespace duilib2
{

FileSystemArchive::FileSystemArchive(const String& name, const String& archType)
	: Archive(name, archType)
{

}

FileSystemArchive::~FileSystemArchive()
{
	unload();
}

void FileSystemArchive::load()
{
	// do nothing
}

void FileSystemArchive::unload()
{
	// do nothing
}

RawDataContainerPtr FileSystemArchive::open(const String& fileName)
{
	// mName 文件夹
	// 在文件夹中找到fileName指定的文件
	// fileName暂不支持子目录，比如 a/b.txt

	String path = getName();
	if (path.at(path.length() - 1) != '\\' ||
		path.at(path.length() - 1) != '/')
	{
		path += '/';
	}
	path += fileName;

	std::ifstream file(path.toLocal8Bit().data(), std::ios::in | std::ios::binary);
	if (!file)
	{
		DUILIB2_EXCEPT(Exception::ERR_FILE_NOT_FOUND,
							 "Cannot open file" + fileName, "FileSystemArchive::open");
	}

	std::ostringstream strStream;
	strStream << file.rdbuf();
	std::string str = strStream.str();

	unsigned char* rawData = new unsigned char[str.size()];
	for (int i = 0; i < (int)str.size(); ++i)
	{
		rawData[i] = (unsigned char)str[i];
	}

	RawDataContainerPtr ret(new RawDataContainer);
	ret->setData(rawData);
	ret->setSize((int)str.size());
	return ret;
}

FileSystemArchiveFactory::FileSystemArchiveFactory()
{

}

FileSystemArchiveFactory::~FileSystemArchiveFactory()
{

}

const String& FileSystemArchiveFactory::getType() const
{
	static String name = "FileSystem";
	return name;
}

Archive* FileSystemArchiveFactory::createInstance(const String& name)
{
	return new FileSystemArchive(name, "FileSystem");
}

void FileSystemArchiveFactory::destroyInstance(Archive* archive)
{
	delete archive;
}

}
