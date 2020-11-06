#include "storedcalc.h"
#include <lib_global.h>

QChar StoredCalc::getOperandSymbol() const
{
    switch (operation) {
    case CalcLibrary::Substraction:
        return '-';
    case CalcLibrary::Addition:
        return '+';
    case CalcLibrary::Multiplication:
        return '*';
    case CalcLibrary::Division:
        return '/';
    }
    return QChar();
}

QString StoredCalc::getStoredString() const
{
    return QString::number(operandA) + " " +  getOperandSymbol() + " " +  QString::number(operandB);
}
