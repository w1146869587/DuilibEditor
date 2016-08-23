#ifndef ARCHIVEFACTORY_H
#define ARCHIVEFACTORY_H

#include <duilib2_global.h>
#include <Archive.h>

namespace duilib2
{

class ArchiveFactory
{
public:
	ArchiveFactory() {}
	virtual ~ArchiveFactory() {}

	/**
	 * @brief
	 *     Returns the factory type.
	 *
	 * @return
	 *     The factory type.
	 */
	virtual const String& getType() const = 0;

	/**
	 * @brief
	 *     Create a new object.
	 *
	 * @param fileName
	 *     The Name of the object to create.
	 *
	 * @return
	 *     An Object created by the factory.
	 */
	virtual Archive* createInstance(const String& name) = 0;

	/**
	 * @brief
	 *     Destroys an object which was created by this factory.
	 *
	 * @param archive
	 *     Pointer to the object to destroy.
	 */
	virtual void destroyInstance(Archive* archive) = 0;
};

}


#endif // ARCHIVEFACTORY_H
