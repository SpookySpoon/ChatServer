#include <QCoreApplication>
#include <QThread>
#include "tcpmsgserver.h"
#include "tcpconnection.h"
int main(int argc, char *argv[])
{
    //SomeChanges obana one and Anothe One aga
    //another line and another one
    QCoreApplication a(argc, argv);
    qDebug()<<"Main thread is "<<QThread::currentThreadId();
    TcpMsgServer opa;
    return a.exec();
}
