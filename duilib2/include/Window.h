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
	virtual Point getPosition(bool relativeToMainWindow = false) const = 0;

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

	/**
	 * @brief getRenderTarget
	 * @return
	 */
	RenderTarget* getRenderTarget();

	/**
	 * @brief setRenderTarget
	 * @param renderTarget
	 */
	void setRenderTarget(RenderTarget* renderTarget);


	/**
	 * @brief Convert screen point to local point.
	 * @param screenPos
	 * @return
	 */
	Point screenToLocal(const Point& screenPos) const;

	/**
	 * @brief Convert local point to screen point.
	 * @param localPos
	 * @return
	 */
	Point localToScreen(const Point& localPos) const;


	virtual bool onMouseLeftButtonDown(const MouseEventArgs& eventArgs);
	virtual bool onMouseLeftButtonUp(const MouseEventArgs& eventArgs);
	virtual bool onMouseRightButtonDown(const MouseEventArgs& eventArgs);
	virtual bool onMouseRightButtonUp(const MouseEventArgs& eventArgs);
	virtual bool onMouseMidButtonDown(const MouseEventArgs& eventArgs);
	virtual bool onMouseMidButtonUp(const MouseEventArgs& eventArgs);
	virtual bool onMouseLeftButtonDoubleClick(const MouseEventArgs& eventArgs);
	virtual bool onMouseMove(const MouseEventArgs& eventArgs);

	// some functions used by DuilibEditor
	typedef std::map<String, Property> PropertyMap;
	typedef std::vector<std::pair<String, PropertyMap>> PropertyMaps;
	// return properties categorised by class names
	virtual PropertyMaps _getProperties() const;

protected:
	/**
	 * @brief
	 *     Render the window's content.
	 */
	virtual void render();

private:
	String mName;
	Window* mParent;
	std::vector<Window*> mChildren;
	RenderTarget* mRenderTarget;
};

} // namespace duilib2

#endif // WINDOW_H
