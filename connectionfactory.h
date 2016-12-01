#pragma once

class TcpMsgServer;

class ConnectionFactory
{
public:
    ConnectionFactory();
    static void createConnection(const int SocketDescriptor, TcpMsgServer* refServer=nullptr);
};
