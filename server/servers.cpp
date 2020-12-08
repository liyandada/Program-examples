#include "servers.h"
#include <QDebug>
#include <QDBusMessage>
#include <QDBusConnection>

servers::servers(QString value)
{
    m_value = value;
}

int servers::maxValue()
{
    return 100;
}
int servers::minValue()
{
    return 0;
}
QString servers::value(QString arg)
{
    //21-24 发送信号
    QDBusMessage message = QDBusMessage::createSignal("/test/objects", "com.scorpio.test.value", "kkk");
    message<<arg;
    QDBusConnection::sessionBus().send(message);
    qDebug()<<"value:"<<arg<<message;
    return m_value;
}
