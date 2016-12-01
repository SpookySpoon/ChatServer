#include <QDateTime>
#include "tcpconnection.h"
#include "protobytes.h"
#include "messageformat.pb.h"

TcpConnection::TcpConnection(const int SocketDescriptor, QObject *parent)
    :QTcpSocket(parent), mySocketDescriptor(SocketDescriptor)
{
}

void TcpConnection::initializePeer()
{
    if (!this->setSocketDescriptor(mySocketDescriptor))
    {
        emit disconnected();
        return;
    }
    else
    {
        QString mes="Greetings, stranger! What is your name?";
        serverMessage(mes);
    }
}

void TcpConnection::receiveMessage()
{
    if(!idRequestState)
    {
        emit broadcastMessage(operationRecieve());
    }
    else
    {
        QString name=operationRecieve().split("[::]").at(0);
        user=name.left(15);
        emit checkName(user);
    }
}

void TcpConnection::nameCheckResults(bool result)
{
    if(user.isEmpty())
    {
        QString greetMes=tr("AHOHUMYCbI UDYT HA XYU!");
        serverMessage(greetMes);
        this->waitForBytesWritten();
        this->abort();
    }
    else if(result)
    {
        QString greetMes=QString("The name is already in use. Please, choose another one.");
        serverMessage(greetMes);
    }
    else
    {
        QString greetMes=QString("Welcome, dear %1, to this amazing chat!").arg(user);
        serverMessage(greetMes);
        idRequestState=false;
    }
}

void TcpConnection::operationSend(const QString& message)
{
    if(this->isOpen())
    {
        QStringList bufferList=message.split("[::]");
        chatMes::hello protoMessage;
        {
            protoMessage.set_mestext(bufferList.at(0).toLatin1().data());
            QString tempStr = bufferList.at(1);
            protoMessage.set_datetime(tempStr.toLongLong());
            protoMessage.set_nickname(user.toStdString());
        }
        this->write(ProtoBytes<chatMes::hello>::protoToByteArray(protoMessage));
    }
    else
    {
        emit disconnected();
    }
}
QString TcpConnection::operationRecieve()
{
    chatMes::hello protoMessage;
    QByteArray incomingMessage=this->readAll();
    protoMessage=ProtoBytes<chatMes::hello>::protoFromByteArray(incomingMessage);
    QString result = QString("%1[::]%2").arg(QString::fromStdString(protoMessage.mestext())).arg(protoMessage.datetime());
    return result;
}

void TcpConnection::serverMessage(const QString& message)
{
    QString tempString=user;
    user="ServerT1000";
    std::uint64_t servTimeInt = QDateTime::currentDateTimeUtc().toMSecsSinceEpoch()/1000;
    QString servTime = QString("%1").arg(servTimeInt);
    operationSend(QString("%1[::]%2").arg(message).arg(servTime));
    user=tempString;
}

void TcpConnection::onDisconnection()
{
    emit deleteUser(user);
}
