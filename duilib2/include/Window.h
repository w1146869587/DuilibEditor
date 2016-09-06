#ifndef WINDOW_H
#define WINDOW_H

#include <duilib2_global.h>
#include <vector>

namespace duilib2
{

class DUILIB2SHARED_EXPORT Window
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

private:
	String mName;
	Window* mParent;
	std::vector<Window*> mChildren;
};

} // namespace duilib2

#endif // WINDOW_H
