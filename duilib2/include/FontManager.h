#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <duilib2_global.h>
#include <Singleton.h>

namespace duilib2
{

class FontManager : public Singleton<FontManager>
{
public:
	FontManager();
	~FontManager();

};

} // namespace duilib2


#endif // FONTMANAGER_H
