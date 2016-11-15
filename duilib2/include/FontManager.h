#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <duilib2_global.h>
#include <Singleton.h>
#include <Font.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT FontManager : public Singleton<FontManager>
{
public:
	FontManager();
	~FontManager();

	/**
	 * @brief addFont
	 * @param font
	 */
	void addFont(const Font& font);


};

} // namespace duilib2


#endif // FONTMANAGER_H
