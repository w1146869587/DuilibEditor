#ifndef QTRESARCHIVE_H
#define QTRESARCHIVE_H

#include <Archive.h>

namespace duilib2
{

class QtResArchive : public Archive
{
public:
	QtResArchive() : Archive("test", "test") {}
	virtual ~QtResArchive() {}
};

}


#endif // QTRESARCHIVE_H
