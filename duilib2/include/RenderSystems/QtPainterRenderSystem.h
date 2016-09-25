#ifndef QTPAINTERRENDERSYSTEM_H
#define QTPAINTERRENDERSYSTEM_H

#include <RenderSystem.h>

namespace duilib2
{

class QtPainterRenderSystem : public RenderSystem
{
public:
	QtPainterRenderSystem();
	virtual ~QtPainterRenderSystem();

	/// @copydoc RenderSystem::fillRect
	virtual void fillRect(int x, int y, int width, int height, const Color& color);

private:
};

} // namespace duilib2

#endif // QTRENDERSYSTEM_H
