#ifndef CONTROL_H
#define CONTROL_H

#include <duilib2_global.h>
#include <Window.h>

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
	virtual Point getPosition() const;

protected:
	virtual void render(RenderTarget* renderTarget);

private:
	static String sTypeName;
};

} // namespace duilib2


#endif  // CONTROL_H
