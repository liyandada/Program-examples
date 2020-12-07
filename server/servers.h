#ifndef SERVERS_H
#define SERVERS_H

#include <QObject>

class servers : public QObject
{
    Q_OBJECT
    //定义Interface名称为com.scorpio.test.value
    Q_CLASSINFO("D-Bus Interface", "com.scorpio.test.value")
public:
    servers(int value);

public slots:
    int maxValue();
    int minValue();
    int value();
private:
    int m_value;

Q_SIGNALS: // SIGNALS
    int kkk();

};

#endif // SERVERS_H
