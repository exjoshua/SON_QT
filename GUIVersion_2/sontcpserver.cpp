#include "sontcpserver.h"

SonTcpServer::SonTcpServer(QObject *parent) :
    QTcpServer(parent)
{
}
void SonTcpServer::StartServer()
{
    if(!this->listen(QHostAddress::Any, 12345))
    {
        qDebug() << "Coule not start server";
    }
    else
    {
        qDebug() << "listening.....";
    }
    countNum = 0;

}
void SonTcpServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug()<< socketDescriptor <<"connecting....";
    /*按顺序添加socket描述符，先连先进*/
     socketList.append(socketDescriptor);
     /*字典用于连接显示值与描述符*/
     countNum++;
     QString str = QString("eNb%1").arg(countNum);
     socketMap[socketDescriptor] = str;

     thread = new SocketThread(socketDescriptor, this);
//     发送描述符信号


     connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
     thread->start();
}
