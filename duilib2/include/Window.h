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

//	virtual bool onLeftButtonDown();
//	virtual bool onRightButtonDown();
//	virtual bool onLeftButtonUp();
//	virtual bool onRightButtonUp();
//	virtual bool onLeftButtonClick();
//	virtual bool onLeftButtonDoubleClick();
//	virtual bool onMouseMove();


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
