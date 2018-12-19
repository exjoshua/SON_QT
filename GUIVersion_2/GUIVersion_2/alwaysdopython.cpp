#include "alwaysdopython.h"


QMutex* alwaysdoPython::mutex = new QMutex;
alwaysdoPython::alwaysdoPython(QObject *parent) : QObject(parent)
{
    count = 0;
}

void alwaysdoPython::startTime()
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &alwaysdoPython::judgeCondition);
    timer->start(2000);

}

void alwaysdoPython::judgeCondition()
{
    if(Widget::judge_id == 1)
    {
        QString extraCMD;
        commandPy = "python3 /home/nano/12-5python/12-19python/self_optimization.py --flag=0";
        extraCMD = " --eNB 2";
        commandPy = commandPy + extraCMD;
        do_work(commandPy);
        //Widget::judge_id = 0;
    }

    else
    {
        qDebug() << "－－－－－－－－－首先配置PCI－－－－－－－－－";
        commandPy = "python3 /home/nano/12-5python/12-19python/self_optimization.py ";
        do_work(commandPy);
        Widget::judge_id = 1;
        //达到一定要求后judge_id = 1

    }
}
void alwaysdoPython::do_work(QString command)
{

    QByteArray ba;
    ba = command.toLocal8Bit();
    //qDebug() <<"eeee";
    /*利用进程执行python程序并通过文本文件进行数据交互*/
    //system("python3 /home/nano/12-5python/self_optimization.py");
    mutex->lock();
    system(ba.data());
    QThread::sleep(2);
    mutex->unlock();
    count++;
    qDebug() << "count:" << count ;
    //TODO:读取数据写入xmap，做到实时更新
    emit emit_freshXmap();
}
