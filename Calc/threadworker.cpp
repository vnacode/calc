#include "threadworker.h"


//void JobCalc::pause()
//{
//    auto const dispatcher = QThread::currentThread()->eventDispatcher();
//    if (!dispatcher) {
//         qDebug() << "thread with no dispatcher";
//        return;
//    }

//    if (state != RUNNING)
//        return;

//    state = PAUSED;
//    qDebug() << "paused";
//    do {
//        dispatcher->processEvents(QEventLoop::WaitForMoreEvents);
//    } while (state == PAUSED);
//}

//void JobCalc::resume()
//{
//      qDebug() <<"st:"<<state;
//    if (state == PAUSED) {
//        state = RUNNING;

//        qDebug() << "resumed";
//    }
//}

//void JobCalc::cancel() {
//    if (state != IDLE) {
//        state = IDLE;
//        qDebug() << "cancelled";
//    }
//}

//double ThreadWorker::DoIt (int TypeWork, double OperandA, double OperandB, int &ErrorCode)
//{
//    switch (TypeWork)
//    {
//     case Operations::TypeWork::Addition: return (OperandA+OperandB);
//     case Operations::TypeWork::Substraction: return (OperandA-OperandB);
//     case Operations::TypeWork::Division:
//    {
//        if (OperandB!=0)
//        return (OperandA/OperandB); else return -1;
//        ErrorCode=0;
//    }
//     case Operations::TypeWork::Multiplication: return (OperandA*OperandB);
//    }
//}

//QString ThreadWorker::findoperation(Operations::TypeWork op)
//{
//    switch (op)
//    {
//     case Operations::TypeWork::Addition: return "+";
//     case Operations::TypeWork::Substraction: return "-";
//     case Operations::TypeWork::Division: return "/";
//     case Operations::TypeWork::Multiplication: return "*";
//    }
//}


//void ThreadWorker::doWork()
//{
//    qDebug()<<"ww"<<this->thread()->currentThreadId();

//    if (state == PAUSED)
//        // treat as resume
//        state = RUNNING;

//    if (state == RUNNING)
//        return;

//    state = RUNNING;
//    qDebug() << "started";
//    emit started();
//    // This loop simulates the actual work
//    for (auto i = 0u;  state == RUNNING;  ++i)
//    {

//        if ((QDateTime::currentDateTime().toSecsSinceEpoch()-Storage::getInstance()->timestamp)>(15000 / 1000))
//        {
//             if(regim==ThreadWorker::Mode::ThreadOne)
//             {
//                   QMutexLocker locker(&mutex);
//                   if(!Storage::getInstance()->calcdata.empty())
//                   {

//                     StoredCalc val= Storage::getInstance()->calcdata.front();
//                     qDebug()<<"queue not empty";
//                     int resultErr;//
//                     double result=DoIt(val.operation,val.operandA,val.operandB,resultErr); //здесь внешняя бибилотека
//                     //emit
//                     Storage::getInstance()->lm->addToConsole("Запрос операции: "+QString::number(val.operandA,'f', 4)+findoperation(static_cast<Operations::TypeWork>(val.operation))+QString::number(val.operandB,'f', 4), Storage::getInstance()->lm->ConsoleGreen);
//                     Storage::getInstance()->resultdata.push({val.operandA,val.operandB,val.operation,resultErr,result});
//                     //QThread::msleep(15000);// ждем 5 сек
//                     Storage::getInstance()->calcdata.pop();
//                     Storage::getInstance()->timestamp = QDateTime::currentDateTime().toSecsSinceEpoch();
//                   }
//                }
//        }

//        if(regim==ThreadWorker::Mode::ThreadTwo)
//        {
//            QMutexLocker locker(&mutex);
//            if(!Storage::getInstance()->resultdata.empty())
//            {
//               qDebug()<<"queue2 not empty";
//               StoredCalc val= Storage::getInstance()->resultdata.front();
//             //  Storage::getInstance()->lm->addToConsole("Результат операции: "+QString::number(val.operandA,'f', 4)+findoperation(static_cast<Operations::TypeWork>(val.operation))+QString::number(val.operandB,'f', 4)+"="+QString::number(val.result,'f', 4), Storage::getInstance()->lm->ConsoleBlue);
//               qDebug()<<QString::number(val.operandA,'f', 4)+findoperation(static_cast<Operations::TypeWork>(val.operation))+QString::number(val.operandB,'f', 4)+"="+QString::number(val.result,'f', 4);
//               Storage::getInstance()->setDisplayData(QString::number(val.operandA)+findoperation(static_cast<Operations::TypeWork>(val.operation))+QString::number(val.operandB)+"="+QString::number(val.result));
//               Storage::getInstance()->resultdata.pop();
//            }
//        }
//          if (isCancelled()) break;
//    }

//    qDebug() << "finished";
//    emit finished();
//}


//void Storage::doCalc(double operandA, double operandB, int typeoperation)
//{

//   // qDebug()<<operandA<<operandB<<typeoperation;
//    //Storage::getInstance()->calcdata.push({operandA,operandB,typeoperation});
//   // Storage::getInstance()->timestamp=QDateTime::currentDateTime().toSecsSinceEpoch();

//}

//void ThreadWorker::resumed()
//{
//  this->cancel();
//  this->doWork();
//}
