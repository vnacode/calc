#include "lib.h"
using namespace CalcLibrary;

double Lib::DoIt(int typeWork, double OperandA, double OperandB, int &ErrorCode)
{
    switch (typeWork)
    {
     case TypeWork::Addition: return (OperandA + OperandB);
     case TypeWork::Substraction: return (OperandA - OperandB);
     case TypeWork::Division:
    {
        if (OperandB != 0)
        return (OperandA/OperandB);
        else
        {
            ErrorCode = 0;
            return -1;
        }
    }
     case TypeWork::Multiplication: return (OperandA * OperandB);
    }
    return 0;
}

