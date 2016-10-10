#ifndef QTMAINWINDOW_H
#define QTMAINWINDOW_H

#include <duilib2_global.h>
#include <MainWindow.h>
#include <WindowFactory.h>
#include <QDialog>
#include <PropertyTypes.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT QtMainWindow : public QDialog, public MainWindow
{
	Q_OBJECT

public:
	QtMainWindow(const String& name);
	virtual ~QtMainWindow();

	// virtual functions from QDialog
	virtual void paintEvent(QPaintEvent* event);
	virtual void mouseMoveEvent(QMouseEvent *event);

	/// @copydoc Window::showModal
	virtual String showModal();


private:
	void initWindow();

private:
	Rect mDragArea;  // 允许按住鼠标左键拖动窗口的区域
};


class DUILIB2SHARED_EXPORT QtMainWindowFactory : public WindowFactory
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
