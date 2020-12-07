#ifndef SERVERS_H
#define SERVERS_H

#include <QObject>

class client : public QObject
{
    Q_OBJECT

public:
    client(int value);

};

#endif // SERVERS_H
