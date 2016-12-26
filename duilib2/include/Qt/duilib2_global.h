#ifndef DUILIB2_GLOBAL_H
#define DUILIB2_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QString>

#if defined(DUILIB2_LIBRARY)
#  define DUILIB2SHARED_EXPORT Q_DECL_EXPORT
#else
#  define DUILIB2SHARED_EXPORT Q_DECL_IMPORT
#endif

#if defined(_MSC_VER)
#  pragma warning(disable:4661)
#endif

typedef QString String;

#endif // DUILIB2_GLOBAL_H
