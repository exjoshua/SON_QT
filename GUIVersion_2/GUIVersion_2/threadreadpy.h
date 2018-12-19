#ifndef THREADREADPY_H
#define THREADREADPY_H

#include <QThread>
#include <QDebug>
#include <QFile>
#include "alwaysdopython.h"


class alwaysdoPython;

class threadReadPy : public QThread
{
    Q_OBJECT
public:
    explicit threadReadPy(QString name,QObject *parent = 0);
    void run();
    QString fileName;
    QString res;
signals:
    void emit_endThread();
public slots:

};

#endif // THREADREADPY_H
