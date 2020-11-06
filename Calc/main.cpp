#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <enums.h>
#include <QThread>
#include <QIcon>
#include <QQmlContext>
#include "threadworker.h"
#include "listmodel.h"
#include <queues/queuerequests.h>

#include "lib_global.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    app.setQuitOnLastWindowClosed(true);
    app.setWindowIcon(QIcon(":/images/calculator.png"));

    QQmlApplicationEngine engine;
    qmlRegisterUncreatableMetaObject(
      CalcLibrary::staticMetaObject, // static meta object
      "CalcLibrary",                // import statement (can be any string)
      1, 0,                          // major and minor version of the import
      "CalcLibrary",                 // name in QML (does not have to match C++ name)
      "Error: only enums"            // error in case someone tries to create a MyNamespace object
    );
    QueueRequests *qe = new QueueRequests;
    QueueResults *qr = new QueueResults(qe);
    qe->setQueueResult(qr);
    QThread *th1 = new QThread;
    qe->moveToThread(th1);
    QObject::connect(th1, &QThread::started, qe, &QueueRequests::work);
    th1->start();

    QThread *th2 = new QThread;
    qr->moveToThread(th2);
    QObject::connect(th2, &QThread::started, qr, &QueueResults::work);
    th2->start();

    QObject::connect(qe, &QueueRequests::queuemsg, listmodel::getInstance(), &listmodel::addToConsole);
    QObject::connect(qr, &QueueResults::queuemsg, listmodel::getInstance(), &listmodel::addToConsole);


    engine.rootContext()->setContextProperty("resultQueue", qr);
    engine.rootContext()->setContextProperty("listmodel", listmodel::getInstance());

    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    //QObject *rootobject= engine.rootObjects()[0];
   // QObject::connect(Storage::getInstance(),SIGNAL(resdisplayChanged(QString)),rootobject,SIGNAL(qmlReceive(QString)));

    return app.exec();
}
