#ifndef SOCKETTHREAD_H
#define SOCKETTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class SocketThread : public QThread
{
    Q_OBJECT
public:
    explicit SocketThread(qintptr id, QObject *parent = 0); //重写析构函数
    void run();

signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();
    void sendTest(QString data);
private:
    QTcpSocket *socket;
    qintptr socketDescriptor;
};

#endif // SOCKETTHREAD_H
