#ifndef THREADWORKER_H
#define THREADWORKER_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QAbstractEventDispatcher>
#include <queue>
#include "enums.h"
#include <QDateTime>
#include <QMutexLocker>
#include <QMutex>
#include <listmodel.h>


//class JobCalc : public QObject
//{
//    Q_OBJECT

//public:

//    explicit JobCalc(QObject *parent = 0): QObject(parent)
//    {
//    }

//signals:
//    void started();
//    void finished();

//public slots:
//    void pause();
//    void resume();
//    void cancel();


//protected:

//    enum State { IDLE, RUNNING, PAUSED };

//    State state = IDLE;

//    bool isCancelled() {
//        auto const dispatcher = QThread::currentThread()->eventDispatcher();
//        if (!dispatcher) {
//            qCritical() << "thread with no dispatcher";
//            return false;
//        }
//        dispatcher->processEvents(QEventLoop::AllEvents);
//        return state == IDLE;
//    }
//signals:

//};


//class Storage: public QObject
//{
//  Q_OBJECT
//public:

//    Q_SIGNAL void resdisplayChanged(QString data );
//    explicit Storage(){}
//    static Storage *getInstance()
//    {
//        static Storage dat;
//        return &dat;
//    }

//    listmodel *lm;

//    Q_PROPERTY(QString resdisplay READ resdisplay WRITE setDisplayData NOTIFY resdisplayChanged)

//    void setDisplayData(const QString &a) {
//         if (a != m_resdisplay) {
//             m_resdisplay = a;
//             emit resdisplayChanged(m_resdisplay);
//         }
//     }

//   /* void setListView(const QString &a)
//    {
//         lm->addToConsole()
//     }*/
//     QString resdisplay() const {
//         return m_resdisplay;
//     }

//     uint timestamp=0;

//    Q_INVOKABLE void doCalc(double operandA, double operandB, int typeoperation);

//    std::queue<StoredCalc> calcdata;
//    std::queue<StoredCalc> resultdata;

// private:
//    QString m_resdisplay;
//};



//class ThreadWorker : public JobCalc
//{
//    Q_OBJECT


// public:
//    QMutex mutex;
//    enum Mode {ThreadOne, ThreadTwo};
//    Mode regim;
//    long waittime;

//    explicit ThreadWorker(Mode Rezim,QObject *parent = 0 ): JobCalc(parent),regim(Rezim)
//    {
//    }

//    ~ThreadWorker()
//    {
//     }

//    void doWork();

//    Q_SLOT void resumed();

//    double DoIt(int TypeWork, double OperandA, double OperandB, int &ErrorCode);
//    QString findoperation(Operations::TypeWork op);



//};

#endif // THREADWORKER_H
