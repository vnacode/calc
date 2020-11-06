#ifndef STOREDCALC_H
#define STOREDCALC_H

#include <QObject>

class StoredCalc
{
     public:
        StoredCalc(double OperandA ,double OperanB, int Operation, int Errorcode = 0)
            : operandA(OperandA),
              operandB(OperanB),
              operation(Operation),
              errorcode(Errorcode) {   }

        void clear()
        {
            operandA = 0;
            operandB = 0;
            operation = -1;
            errorcode = -1;
        }

        QChar getOperandSymbol() const;

        StoredCalc(const StoredCalc &other)
        {
            operandA = other.operandA;
            operandB = other.operandB;
            operation = other.operation;
            errorcode = other.errorcode;
        }

        StoredCalc &operator =(const StoredCalc &other)
        {
            this->operandA = other.operandA;
            this->operandB = other.operandB;
            this->operation = other.operation;
            this->errorcode = other.errorcode;
            return  *this;
        }

        StoredCalc &operator =(StoredCalc &&other)
        {
            this->operandA = other.operandA;
            this->operandB = other.operandB;
            this->operation = other.operation;
            this->errorcode = other.errorcode;
            other.clear();
            return  *this;
        }


        QString getStoredString() const;
        double operandA;
        double operandB;
        int operation;
        int errorcode;
    };


#endif // STOREDCALC_H
