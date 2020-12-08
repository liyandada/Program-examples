#include "mainwindow.h"
#include <QDBusConnection>
#include <QApplication>
#include "servers.h"
#include <QDBusError>
#include <QDebug>
#include "valueAdaptor.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //************************************
    //用普通方法连接DBUS********************
    //************************************

    //建立到session bus的连接
    QDBusConnection connection = QDBusConnection::sessionBus();
    //在session bus上注册名为com.scorpio.test的服务
    if(!connection.registerService("com.scorpio.test"))
    {
        qDebug() << "error:" << connection.lastError().message();
        exit(-1);
    }
    servers object("hello");
       //注册名为/test/objects的对象，把类Object所有槽函数导出为object的method
       connection.registerObject("/test/objects", &object,QDBusConnection::ExportAllSlots| QDBusConnection :: ExportAllSignals);

//    //************************************
//    //调用Adaptor类注册Object对象***********
//    //************************************

//    QDBusConnection connection = QDBusConnection::sessionBus();
//    servers object(60);
//    //ValueAdaptor是qdbusxml2cpp生成的Adaptor类
//       ValueAdaptor valueAdaptor(&object);
//       if (!connection.registerService("com.scorpio.test"))
//       {
//           qDebug() << connection.lastError().message();
//           exit(1);
//       }
//       connection.registerObject("/test/objects", &object);



    MainWindow w;
    w.show();
    return a.exec();
}
