#ifndef CONTROL_H
#define CONTROL_H

#include <duilib2_global.h>
#include <WindowFactory.h>
#include <Window.h>
#include <RenderSystem.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Control : public Window
{
public:
	Control(const String& name);
	virtual ~Control();

	/// @copydoc Window::getType
	virtual String getType() const;

	/// @copydoc Window::showModal
	virtual String showModal();

	/// @copydoc Window::getWidth
	virtual int getWidth() const;

	/// @copydoc Window::getHeight
	virtual int getHeight() const;

	/// @copydoc Window::getPosition
	virtual Point getPosition(bool relativeToMainWindow = false) const;

	/**
	 * @brief isFloat
	 * @return
	 */
	bool isFloat() const;

	// internal use, invoke by layout
	void _setPosition(const Point& pos);
	void _setWidth(int width);
	void _setHeight(int height);

protected:
	virtual void render();
	virtual void drawBackgroundColor(RenderSystem* rs);
	virtual void drawBackgroundImage(RenderSystem* rs);
	virtual void drawStatusImage(RenderSystem* rs);
	virtual void drawText(RenderSystem* rs);
	virtual void drawBorder(RenderSystem* rs);

private:
	static String sTypeName;
	Point mPosition;
	int mWidth;
	int mHeight;
};

class DUILIB2SHARED_EXPORT ControlFactory : public WindowFactory
{
public:
	ControlFactory();
	virtual ~ControlFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // CONTROL_H
