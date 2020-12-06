#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>


class workthread : public QThread
{
    Q_OBJECT
public:
    workthread();


protected:
    void run();
    QMutex mutex;


signals:

};

#endif // WORKTHREAD_H
