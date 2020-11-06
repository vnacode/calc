#include "queueresults.h"
#include "queuerequests.h"
#include <listmodel.h>
#include <QDebug>

QueueResults::QueueResults(QueueRequests *queueRequest, QObject *parent) : QObject(parent)
{
    m_queueRequest = queueRequest;
}

void QueueResults::addCalc(double operandA, double operandB, int operation)
{
    auto calc = StoredCalc(operandA, operandB, operation, 0);
    m_queueRequest->addStoredCalc(calc);
}

void QueueResults::work()
{
    forever {
        if (m_resultQueue.size() > 0)
        {
            emit queuemsg(m_resultQueue.front(), 1);
            m_resultQueue.pop();
        }
    }
}

void QueueResults::addNewResult(const double result)
{
    m_resultQueue.push(QString::number(result));
}

