#ifndef QTMAINWINDOW_H
#define QTMAINWINDOW_H

#include <duilib2_global.h>
#include <MainWindow.h>
#include <WindowFactory.h>

namespace duilib2
{

class QtMainWindow : public MainWindow
{
public:
	QtMainWindow(const String& name);
	virtual ~QtMainWindow();

};


class QtMainWindowFactory : public WindowFactory
{
public:
	QtMainWindowFactory();
	virtual ~QtMainWindowFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

}

#endif // QTMAINWINDOW_H
