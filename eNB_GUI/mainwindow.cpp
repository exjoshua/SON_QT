#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString macAddress;
    /*获取mac地址*/
    macAddress = getHostMacAddress();
    ui->lineEdit->setText(macAddress);
    /*初始化socket*/
    socket = new QTcpSocket(this);
    socket->connectToHost(QHostAddress::LocalHost, 12345);
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::connected()
{
    qDebug() << "连接上了";
}
void MainWindow::readyRead()
{
    QString recvStr,confStr;
    QByteArray recvByte;
    qint8 bandWidth, transP, recvP;
    double centerF;
    recvByte = socket->readAll();
    recvStr = recvByte;
    qDebug() << recvStr;
    //切割字符串，取出配置部分，并用逗号替换空格，并移除字符串两端的空白符
    confStr = recvStr.section("              ", 2, 6).replace("              ", ",").trimmed();
    qDebug() << confStr;
    centerF = confStr.section(",",0,0).toDouble();
    bandWidth = confStr.section(",",1,1).toInt();
    transP = confStr.section(",",2,2).toInt();
    recvP = confStr.section(",",3,3).toInt();
    ui->lineEdit_3->setText(QString::number(bandWidth));
    ui->lineEdit_5->setText(QString::number(transP));
    ui->lineEdit_4->setText(QString::number(centerF));
    ui->lineEdit_9->setText(QString::number(recvP));
}


//Mac地址获取函数
QString MainWindow::getHostMacAddress()
{
    QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces(); //获取所有网络接口列表
    int nCnt = nets.count();
    QString strMacAddr = "";
    for (int i=0; i<nCnt; i++)
    {
        //qDebug() << nets[i].hardwareAddress();
        //如果此网络接口被激活并且正在运行并且不是回环地址，则就是我们需要找的Ｍac地址
        if(nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning) && !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack))
        {
            strMacAddr = nets[i].hardwareAddress();
            break;
        }
    }
    return strMacAddr;
}
