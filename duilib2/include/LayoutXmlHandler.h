#ifndef LAYOUTXMLHANDLER_H
#define LAYOUTXMLHANDLER_H

#include <duilib2_global.h>
#include <XmlHandler.h>
#include <Window.h>
#include <stack>

namespace duilib2
{

/**
 * @brief
 *     Parsing from xml file and generate windows hierarchy
 */
class DUILIB2SHARED_EXPORT LayoutXmlHandler : public XmlHandler
{
public:
	LayoutXmlHandler();
	virtual ~LayoutXmlHandler();

	/**
	 * @brief
	 *     Return the root window that parsing from xml file
	 *
	 * @return
	 *     The root window
	 */
	Window* getLayoutRootWindow();

	/// @copydoc XmlHandler::elementStart
	virtual void elementStart(const String& element, const XmlAttributes& attributes);

	/// @copydoc XmlHandler::elementEnd
	virtual void elementEnd(const String& element);

	/// @copydoc XmlHandler::text
	virtual void text(const String& text);

private:
	void FontElementStart(const XmlAttributes& attributes);
	void DefaultElementStart(const XmlAttributes& attributes);

private:
	Window* mRootWindow;
	std::stack<Window*> mStack;
};

}

#endif // 
