#ifndef ZIPARCHIVE_H
#define ZIPARCHIVE_H

#include <Archive.h>

namespace duilib2
{

class ZipArchive : public Archive
{
public:
	ZipArchive() : Archive("test", "test") {}
	virtual ~ZipArchive() {}
};

}

#endif // ZIPARCHIVE_H
