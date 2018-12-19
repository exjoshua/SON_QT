#include "threadreadpy.h"
#include <QMutex>

threadReadPy::threadReadPy(QString name,QObject *parent) :
    QThread(parent)
{
    fileName = name;
}
void threadReadPy::run()
{
    QString commandPy;
    QString f_str = "";
    QString extraCMD;
    QByteArray ba;
    QByteArray line;
    commandPy = "python3 /home/nano/12-5python/12-19python/" + fileName +".py --flag=0";
    extraCMD = ' --eNB=2';
    commandPy = commandPy + extraCMD;
    ba = commandPy.toLocal8Bit();
    //qDebug() <<"eeee";
    /*利用进程执行python程序并通过文本文件进行数据交互*/
    //system("python3 Coverage_best.py");
    alwaysdoPython::mutex->lock();
    system(ba.data());
    alwaysdoPython::mutex->unlock();


}
