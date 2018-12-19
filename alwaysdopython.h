#ifndef ALWAYSDOPYTHON_H
#define ALWAYSDOPYTHON_H

#include <QObject>
#include <QTimer>
#include <QWaitCondition>
#include <QMutex>
#include "widget.h"
#include <QThread>


class alwaysdoPython : public QObject
{
    Q_OBJECT
public:
    explicit alwaysdoPython(QObject *parent = nullptr);
    static QMutex *mutex;
    int count;
signals:
    void emit_freshXmap();
public slots:
    void startTime();
    void judgeCondition();
public:
    QTimer* timer;
    void do_work(QString command);
    QString commandPy;
};

#endif // ALWAYSDOPYTHON_H
