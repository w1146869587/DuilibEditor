#ifndef EVENTARGS_H
#define EVENTARGS_H

#include <duilib2_global.h>
#include <Types.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT EventArgs
{
public:
	EventArgs();
	virtual ~EventArgs();


};

// 各种事件参数需要完善
// 需要定义键盘各键的值#define KEY_A xx 等等

class DUILIB2SHARED_EXPORT MouseEventArgs : public EventArgs
{
public:
	MouseEventArgs();
	virtual ~MouseEventArgs();

	Point getScreenPos() const;

private:
	Point mScreenPos;
};

} // namespace duilib2

#endif // EVENTARGS_H
