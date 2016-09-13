#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <duilib2_global.h>
#include <Window.h>

namespace duilib2
{

/**
 * @brief
 *     The MainWindow is the top window that contain some control windows
 *
 *     QtMainWindow using QWidget in Qt, Win32MainWindow using a win32 window.
 */
class DUILIB2SHARED_EXPORT MainWindow : public Window
{
public:
	MainWindow(const String& name);
	virtual ~MainWindow();

	/// @copydoc Window::getType
	virtual String getType() const;

private:
	static String sTypeName;
	// ... properties
	// ... events


};

}

#endif // MAINWINDOW_H
