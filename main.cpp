#include <QCoreApplication>
#include <QThread>
#include "tcpmsgserver.h"
#include "tcpconnection.h"
int main(int argc, char *argv[])
{
    //SomeChanges
    QCoreApplication a(argc, argv);
    qDebug()<<"Main thread is "<<QThread::currentThreadId();
    TcpMsgServer opa;
    return a.exec();
}
