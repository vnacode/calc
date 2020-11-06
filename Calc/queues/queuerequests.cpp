#include "queuerequests.h"

#include "lib_global.h"
#include <lib.h>
#include <QThread>
#include <QDebug>
#include "listmodel.h"


QueueRequests::QueueRequests(QObject *parent)
: QObject(parent)
{

}

void QueueRequests::setQueueResult(QueueResults *queueResult)
{
  m_queueResult = queueResult;
}

QueueRequests::QueueRequests(QueueResults *queueResult, QObject *parent) : QObject(parent)
{
    m_queueResult = queueResult;
}

void QueueRequests::work()
{
    using namespace CalcLibrary;
    forever {
        if (m_requestQueue.size() == 0)
            continue;
       auto calc = StoredCalc(m_requestQueue.front());
       emit queuemsg(calc.getStoredString(), 0);
       int errorCode = 0;
       m_requestQueue.pop();
       auto result = CalcLibrary::Lib::DoIt(calc.operation, calc.operandA, calc.operandB, errorCode);
       QThread::msleep(m_interval);
       m_queueResult->addNewResult(result);
    }
}

void QueueRequests::addStoredCalc(const StoredCalc &calc)
{
    m_requestQueue.push(calc);
}

void QueueRequests::setInterval(uint msces)
{
    m_interval = msces;
}
