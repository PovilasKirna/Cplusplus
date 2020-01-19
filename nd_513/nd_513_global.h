#ifndef ND_513_GLOBAL_H
#define ND_513_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ND_513_LIBRARY)
#  define ND_513_EXPORT Q_DECL_EXPORT
#else
#  define ND_513_EXPORT Q_DECL_IMPORT
#endif

#endif // ND_513_GLOBAL_H
