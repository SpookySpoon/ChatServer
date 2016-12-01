#pragma once
#include <QTcpServer>

class TcpMsgServer:public QTcpServer
{
    Q_OBJECT
    QStringList userList;
    qint16 portNumber=50000;
    void lookForFreePort(const QString& ipAddress);
public:
    TcpMsgServer(QObject* parent=nullptr); //Step 1
public slots:
    void sendMessage(const QString& message);
    void checkName(const QString&);
    void deleteName(const QString&);
signals:
    void nameCheckResult(bool);
    void broadcastingMessage(const QString& message);
protected:
    void incomingConnection(qintptr socketDescriptor); //Step 2

};
