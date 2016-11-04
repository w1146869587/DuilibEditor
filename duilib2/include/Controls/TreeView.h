#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <duilib2_global.h>
#include <Controls/List.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT TreeView : public List
{
public:
	TreeView(const String& name);
	virtual ~TreeView();

	/// @copydoc Window::getType
	virtual String getType() const;

	/// @copydoc Window::getWidth
	virtual int getWidth() const;

	/// @copydoc Window::getHeight
	virtual int getHeight() const;

	/// @copydoc Window::getPosition
	virtual Point getPosition() const;

protected:
	virtual void render();

private:
	static String sTypeName;
};

class DUILIB2SHARED_EXPORT TreeViewFactory : public WindowFactory
{
public:
	TreeViewFactory();
	virtual ~TreeViewFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // TREEVIEW_H
