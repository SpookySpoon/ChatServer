#include <QNetworkInterface>
#include "tcpmsgserver.h"
#include "connectionfactory.h"

TcpMsgServer::TcpMsgServer(QObject* parent):
    QTcpServer(parent)
{
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    for (auto i:ipAddressesList)
    {
        if (i != QHostAddress::LocalHost &&
            i.toIPv4Address())
        {
            ipAddress = i.toString();
            break;
        }
    }
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    lookForFreePort(ipAddress);
}

void TcpMsgServer::incomingConnection(qintptr socketDescriptor)
{
    ConnectionFactory::createConnection(socketDescriptor, this);
}

void TcpMsgServer::checkName(const QString& someName)
{
    bool result=true;
    if(!userList.contains(someName))
    {
        userList.append(someName);
        result=false;
    }
    emit nameCheckResult(result);
}

void TcpMsgServer::lookForFreePort(const QString& ipAddress)
{
    if (!this->listen(QHostAddress(ipAddress),portNumber)) {
        if(portNumber<=65534)
        {
            portNumber++;
            lookForFreePort(ipAddress);
        }
        else
        {
            qDebug()<<"Server was not launched, because "<<this->errorString()<<".\n";
        }
    }
    else
    {
        qDebug()<<"It's alive!!!\n";
        qDebug()<<"The server adress is: "<<this->serverAddress().toString()<<":"<<this->serverPort()<<"\n";
    }
}

void TcpMsgServer::sendMessage(const QString& message)
{
    emit broadcastingMessage(message);
}
void TcpMsgServer::deleteName(const QString& user)
{
    userList.removeAll(user);
}




