#ifndef TYPES_H
#define TYPES_H

#include <duilib2_global.h>
#include <PropertyTypes.h>

namespace duilib2
{

class Point
{
public:
	Point();
	Point(int x, int y);
	~Point();

	int mX;
	int mY;
};


} // namespace duilib2

#endif // TYPE_H
