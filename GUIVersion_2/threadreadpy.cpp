#include "threadreadpy.h"

threadReadPy::threadReadPy(QString name,QObject *parent) :
    QThread(parent)
{
    fileName = name;
}
void threadReadPy::run()
{
    QString commandPy;
    QString f_str = "";
    QByteArray ba;
    QByteArray line;
    commandPy = "python3 " + fileName +".py 13";
    ba = commandPy.toLocal8Bit();
    //qDebug() <<"eeee";
    /*利用进程执行python程序并通过文本文件进行数据交互*/
    //system("python3 Coverage_best.py");
    system(ba.data());

}
