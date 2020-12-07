#include "testdemo.h"

testdemo::testdemo(QObject *parent) : QObject(parent)
{
    btn = new QPushButton;
    btn->setText("hello");
}

void testdemo::sendmessage()
{
    qDebug()<<"sendmessage";
}

void testdemo::showlabel()
{
    btn->show();
}

// 19-25 可实现本类的单例，Q_GLOBAL_STATIC宏为单例实现的方法
Q_GLOBAL_STATIC(testdemo, upInstance)
testdemo *testdemo::instance()
{
    qDebug()<<"instance";
    return upInstance;
}
