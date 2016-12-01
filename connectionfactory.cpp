#include <QThread>
#include "connectionfactory.h"
#include "tcpmsgserver.h"
#include "tcpconnection.h"

ConnectionFactory::ConnectionFactory()
{}
void ConnectionFactory::createConnection(const int socketDescriptor, TcpMsgServer *hostingServer)
{
    TcpConnection *someConnection = new TcpConnection(socketDescriptor);
    QThread* myThread = new QThread;
    QObject::connect(myThread,SIGNAL(started()),someConnection,SLOT(initializePeer()));
    QObject::connect(someConnection,SIGNAL(disconnected()),someConnection,SLOT(onDisconnection()));
    QObject::connect(someConnection,SIGNAL(disconnected()),someConnection,SLOT(deleteLater()));
    QObject::connect(someConnection,SIGNAL(destroyed(QObject*)),myThread,SLOT(quit()));
    QObject::connect(myThread,SIGNAL(finished()),myThread,SLOT(deleteLater()));

    QObject::connect(someConnection,SIGNAL(readyRead()),someConnection,SLOT(receiveMessage()));

    QObject::connect(someConnection,SIGNAL(checkName(QString)),hostingServer,SLOT(checkName(QString)));
    QObject::connect(hostingServer,SIGNAL(nameCheckResult(bool)),someConnection,SLOT(nameCheckResults(bool)));
    QObject::connect(someConnection,SIGNAL(deleteUser(QString)),hostingServer,SLOT(deleteName(QString)));

    QObject::connect(someConnection,SIGNAL(broadcastMessage(QString)),hostingServer,SLOT(sendMessage(QString)));
    QObject::connect(hostingServer,SIGNAL(broadcastingMessage(QString)),someConnection,SLOT(operationSend(QString)));

    someConnection->moveToThread(myThread);
    myThread->start();
}
