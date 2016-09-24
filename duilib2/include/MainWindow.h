#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <duilib2_global.h>
#include <Window.h>
#include <utility>

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
	 * @brief
	 *     Get the position of the client area.
	 *
	 * @return
	 *     The position
	 */
	std::pair<int, int> getPosition() const;


protected:
	virtual void render(RenderTarget* renderTarget);
	bool userSetPosition() const;

private:
	static String sTypeName;

	bool mFrameless;
	bool mUserSetPosition; // 是否用户指定了窗口位置
	int  mPosX;            // 窗口位置，x坐标
	int  mPosY;            // 窗口位置，y坐标
	// RoundRect mClipRegion;   // 剪裁区域
	// bool mClipping;     // 是否使用剪裁区域
};

}

#endif // MAINWINDOW_H
