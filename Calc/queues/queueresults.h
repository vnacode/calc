#ifndef QUEUERESULTS_H
#define QUEUERESULTS_H
#include <QObject>
#include <queue>

class QueueRequests;

class QueueResults : public QObject
{
    Q_OBJECT
public:
    explicit QueueResults(QueueRequests *queueRequest, QObject *parent = nullptr);
    Q_INVOKABLE void addCalc(double operandA, double operandB, int operation);
    void work();
    int getQueueSize() const { return  m_resultQueue.size(); }
    void addNewResult(const double result);
    Q_SIGNAL void queuemsg(const QString &msg, int type);
private:
    QueueRequests *m_queueRequest;
    std::queue<QString> m_resultQueue;
};

#endif // QUEUERESULTS_H
