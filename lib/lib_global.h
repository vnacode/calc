#ifndef LIB_GLOBAL_H
#define LIB_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QObject>

namespace CalcLibrary {

#if defined(LIB_LIBRARY)
#  define LIB_EXPORT Q_DECL_EXPORT
#else
#  define LIB_EXPORT Q_DECL_IMPORT
#endif

Q_NAMESPACE
enum TypeWork {
    Substraction,
    Multiplication,
    Division,
    Addition,
    Result
};
Q_ENUM_NS(TypeWork)


enum TypeError {
    NoError,
    divisionbyzero=1

};
Q_ENUM_NS(TypeError)

}


#endif // LIB_GLOBAL_H
