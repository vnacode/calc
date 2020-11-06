#ifndef CALCLIB_H
#define CALCLIB_H

#include <QObject>

class calclib
{
public:
    calclib();
    double DoIt(int TypeWork, double OperandA, double OperandB, int &ErrorCode);
};

#endif // CALCLIB_H
