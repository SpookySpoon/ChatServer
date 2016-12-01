#pragma once
#include <QTcpSocket>

class TcpConnection: public QTcpSocket
{
    Q_OBJECT
    QString operationRecieve();
    void serverMessage(const QString& message);
    QString user;
    int mySocketDescriptor;
    bool idRequestState = true;
public:
    TcpConnection(const int SocketDescriptor=-1, QObject *parent = Q_NULLPTR);
public slots:
    void initializePeer();
    void receiveMessage();
    void operationSend(const QString&);
    void nameCheckResults(bool);
    void onDisconnection();
signals:
    void broadcastMessage(const QString&);
    void checkName(const QString&);
    void deleteUser(const QString&);
};


