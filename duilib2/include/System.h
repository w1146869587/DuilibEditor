#ifndef SYSTEM_H
#define SYSTEM_H

#include <duilib2_global.h>
#include <Singleton.h>
#include <ResourceManager.h>
#include <WindowManager.h>
#include <XmlParser.h>
#include <ArchiveManager.h>
#include <PropertyParserManager.h>
#include <RenderSystem.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT System : public Singleton<System>
{
public:
	System();
	~System();

	/**
	 * @brief
	 *     Initialize the duilib2 system.
	 *
	 * @return
	 *     The singleton pointer.
	 */
	static System* create();

	/**
	 * @brief
	 *     Destroy the duilib2 system.
	 */
	static void destroy();

	/**
	 * @brief getXmlParser
	 * @return
	 */
	XmlParser* getXmlParser() const;

	/**
	 * @brief getRenderSystem
	 * @return
	 */
	RenderSystem* getRenderSystem() const;

private:
	void createXmlParser();
	void addArchiveFactories();
	void addWindowFactores();
	void createRenderSystem();

private:
	ArchiveManager*  mArchiveManager;
	ResourceManager* mResourceManager;
	WindowManager*   mWindowManager;
	PropertyParserManager* mPropertyParserManager;
	XmlParser*       mXmlParser;
	RenderSystem*    mRenderSystem;

};

} // duilib2

#endif // SYSTEM_H
