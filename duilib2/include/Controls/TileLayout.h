#ifndef TILELAYOUT_H
#define TILELAYOUT_H

#include <duilib2_global.h>
#include <Controls/Container.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT TileLayout : public Container
{
public:
	TileLayout(const String& name);
	virtual ~TileLayout();

	/// @copydoc Window::getType
	virtual String getType() const;

	/// @copydoc Window::getWidth
	virtual int getWidth() const;

	/// @copydoc Window::getHeight
	virtual int getHeight() const;

	/// @copydoc Window::getPosition
	virtual Point getPosition() const;

protected:
	virtual void render(RenderTarget* renderTarget);

private:
	static String sTypeName;
};

class DUILIB2SHARED_EXPORT TileLayoutFactory : public WindowFactory
{
public:
	TileLayoutFactory();
	virtual ~TileLayoutFactory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // TILELAYOUT_H
