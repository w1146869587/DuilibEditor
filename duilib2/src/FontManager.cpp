#include <FontManager.h>

namespace duilib2
{

FontManager* Singleton<FontManager>::mSingleton = NULL;

FontManager::FontManager()
{

}

FontManager::~FontManager()
{

}

void FontManager::addFont(const Font& font)
{
	// ...
}

} // namespace duilib2

