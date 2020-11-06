#ifndef QUEUEREQUESTS_H
#define QUEUEREQUESTS_H

#include <QObject>
#include <queue>

#include "storedcalc.h"
#include "queueresults.h"

class QueueRequests : public QObject
{
    Q_OBJECT
public:
    explicit QueueRequests(QObject *parent = nullptr);
    explicit QueueRequests(QueueResults *queueResult, QObject *parent = nullptr);
    void setQueueResult(QueueResults *queueResult);
    void work();
    void addStoredCalc(const StoredCalc& calc);
    Q_INVOKABLE void setInterval(uint msces);
    Q_SIGNAL void queuemsg(const QString &msg, int type);
private:
    uint m_interval = 3000;
    QueueResults *m_queueResult;
    std::queue<StoredCalc> m_requestQueue;

signals:

};

#endif // QUEUEREQUESTS_H
