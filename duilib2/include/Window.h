#ifndef WINDOW_H
#define WINDOW_H

#include <duilib2_global.h>
#include <vector>
#include <PropertySet.h>
#include <RenderTarget.h>
#include <EventSet.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Window
		: public PropertySet
		, public EventSet
{
public:
	Window(const String& name);
	virtual ~Window();

	/**
	 * @brief
	 *     Get the type name of the window, it is equal to the tag name in xml file.
	 *
	 * @return
	 *     The type name of the window.
	 */
	virtual String getType() const = 0;

	/**
	 * @brief showModal
	 * @return
	 */
	virtual String showModal();

	/**
	 * @brief
	 *     Get the width of the window.
	 *
	 * @return
	 */
	virtual int getWidth() const;

	/**
	 * @brief
	 *     Get the height of the window.
	 *
	 * @return
	 */
	virtual int getHeight() const;

	/**
	 * @brief
	 *     Get the position of the window, relative to parent window.
	 *
	 * @return
	 */
	virtual Point getPosition() const = 0;

	/**
	 * @brief
	 *     Get children windows of this window.
	 *
	 * @return
	 *     The children windows
	 */
	std::vector<Window*>& getChildren();
	const std::vector<Window*>& getChildren() const;

	/**
	 * @brief
	 *     Set parent window.
	 *
	 * @param parent
	 *     The pointer of the parent window.
	 */
	void setParent(Window* parent);

	/**
	 * @brief
	 *     Get parent window.
	 *
	 * @return
	 *     The pointer of the parent window.
	 */
	Window* getParent();
	const Window* getParent() const;

	/**
	 * @brief hitTest
	 * @param point
	 * @return
	 */
	bool hitTest(const Point& screenPos) const;

	Point screenToLocal(const Point& screenPos) const;
	Point localToScreen(const Point& localPos) const;


	virtual bool onMouseLeftButtonDown(const MouseEventArgs& eventArgs);
	virtual bool onMouseLeftButtonUp(const MouseEventArgs& eventArgs);
	virtual bool onMouseRightButtonDown(const MouseEventArgs& eventArgs);
	virtual bool onMouseRightButtonUp(const MouseEventArgs& eventArgs);
	virtual bool onMouseMidButtonDown(const MouseEventArgs& eventArgs);
	virtual bool onMouseMidButtonUp(const MouseEventArgs& eventArgs);
	virtual bool onMouseLeftButtonDoubleClick(const MouseEventArgs& eventArgs);
	virtual bool onMouseMove(const MouseEventArgs& eventArgs);


protected:
	/**
	 * @brief
	 *     Render the window's content.
	 *
	 * @param renderTarget
	 */
	virtual void render(RenderTarget* renderTarget);

private:
	String mName;
	Window* mParent;
	std::vector<Window*> mChildren;
};

} // namespace duilib2

#endif // WINDOW_H
