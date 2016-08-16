#ifndef DUILIB2_GLOBAL_H
#define DUILIB2_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DUILIB2_LIBRARY)
#  define DUILIB2SHARED_EXPORT Q_DECL_EXPORT
#else
#  define DUILIB2SHARED_EXPORT Q_DECL_IMPORT
#endif

typedef QString String;

#endif // DUILIB2_GLOBAL_H
