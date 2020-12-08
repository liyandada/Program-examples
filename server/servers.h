#ifndef SERVERS_H
#define SERVERS_H

#include <QObject>

class servers : public QObject
{
    Q_OBJECT
    //定义Interface名称为com.scorpio.test.value
    Q_CLASSINFO("D-Bus Interface", "com.scorpio.test.value")
public:
    servers(QString value);

public slots:
    int maxValue();
    int minValue();
    QString value(QString arg);
private:
    QString m_value;

Q_SIGNALS: // SIGNALS
    QString kkk(QString ret);

};

#endif // SERVERS_H
