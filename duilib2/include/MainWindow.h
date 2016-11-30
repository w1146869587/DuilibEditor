#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <duilib2_global.h>
#include <Window.h>
#include <utility>
#include <RoundRect.h>

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

	/// @copydoc Window::getWidth
	virtual int getWidth() const;

	/// @copydoc Window::getHeight
	virtual int getHeight() const;

	/**
	 * @brief setFrameless
	 * @param enable
	 */
	void setFrameless(bool enable);

	/**
	 * @brief isFrameless
	 * @return
	 */
	bool isFrameless() const;

	/**
	 * @brief
	 *     Set the position of the client area.
	 *     If not set, the client area is in the center of the screen.
	 *
	 * @param x
	 * @param y
	 */
	void setPosition(int x, int y);

	/**
	 * @brief setClipRegion
	 * @param x
	 * @param y
	 * @param width
	 * @param height
	 * @param xRadius
	 * @param yRadius
	 */
	void setClipRegion(int x, int y, int width, int height, int xRadius, int yRadius);

	/**
	 * @brief clearClipRegion
	 */
	void clearClipRegion();


	virtual PropertyMaps _getProperties() const;

protected:
	virtual void render();
	bool userSetPosition() const;
	Point getUserSetPosition() const;

private:
	static String sTypeName;

	bool mFrameless;
	bool mUserSetPosition; // The position is set by user
	int  mPosX;            // Position of the window, x coord
	int  mPosY;            // Position of the window, y coord
	bool mClipping;        // Using clip region
	RoundRect mClipRegion;
};

}

#endif // MAINWINDOW_H
