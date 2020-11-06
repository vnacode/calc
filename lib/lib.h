#ifndef LIB_H
#define LIB_H

#include "lib_global.h"
#include <QObject>


namespace CalcLibrary {

class LIB_EXPORT Lib
{
public:
    static double DoIt (int typeWork, double OperandA, double OperandB, int &ErrorCode);
};


}
#endif // LIB_H
