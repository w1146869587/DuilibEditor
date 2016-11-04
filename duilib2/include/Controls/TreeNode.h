#ifndef TREENODE_H
#define TREENODE_H

#include <duilib2_global.h>
#include <Controls/ListContainerElement.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT TreeNode : public ListContainerElement
{
public:
	TreeNode(const String& name);
	virtual ~TreeNode();

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

class DUILIB2SHARED_EXPORT TreeNodeFactory : public WindowFactory
{
public:
	TreeNodeFactory();
	virtual ~TreeNodeFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // TREENODE_H
