#ifndef TESTDEMO_H
#define TESTDEMO_H

#include <QObject>
#include <QDebug>
#include <QPushButton>

class testdemo : public QObject
{
    Q_OBJECT
public:
    explicit testdemo(QObject *parent = nullptr);

    void sendmessage();
    void showlabel();

    QPushButton *btn;
    static testdemo *instance();

signals:

};

#endif // TESTDEMO_H
