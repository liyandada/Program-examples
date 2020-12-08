#include "mainwindow.h"
#include <QDBusConnection>
#include <QDBusMessage>
#include <QApplication>
//#include "client.h"
#include <QDBusError>
#include <QDBusReply>
#include <QDBusInterface>
#include <QDebug>
#include "valueInterface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


//    //**********************************************************************************
//    //通过QDBusMessage访问Service*******************************************************
//    //**********************************************************************************

//    QDBusMessage message = QDBusMessage::createMethodCall("com.scorpio.test",
//                           "/test/objects",
//                           "com.scorpio.test.value",
//                           "value");

//    //发送消息
//    QDBusMessage response = QDBusConnection::sessionBus().call(message);

//    //判断method是否被正确返回
//      if (response.type() == QDBusMessage::ReplyMessage)
//      {
//          //从返回参数获取返回值
//          int value = response.arguments().takeFirst().toInt();
//          qDebug() << QString("value =  %1").arg(value);
//      }
//      else
//      {
//          qDebug() << "value method called failed!";
//      }


//      //**********************************************************************************
//      //通过QDBusInterface 访问Service*******************************************************
//      //**********************************************************************************


//      // 创建QDBusInterface接口
//        QDBusInterface interface("com.scorpio.test", "/test/objects",
//                                 "com.scorpio.test.value",
//                                 QDBusConnection::sessionBus());
//        if (!interface.isValid())
//        {
//            qDebug() << qPrintable(QDBusConnection::sessionBus().lastError().message());
//            exit(1);
//        }

//        //调用远程的value方法
//        QDBusReply<int> reply = interface.call("value");
//        if (reply.isValid())
//        {
//            int value = reply.value();
//            qDebug() << QString("value =  %1").arg(value);
//        }
//        else
//        {
//            qDebug() << "value method called failed!";
//        }



//        //**********************************************************************************
//        //从D-Bus XML自动生成Proxy类******************************************************
//        //**********************************************************************************


//        // 初始化自动生成的Proxy类com::scorpio::test::value
//        com::scorpio::test::value test("com.scorpio.test",
//                                       "/test/objects",
//                                       QDBusConnection::sessionBus());

//        // 调用value方法
//           QDBusPendingReply<int> reply = test.value();
//           //qdbusxml2cpp生成的Proxy类是采用异步的方式来传递Message，
//           //所以需要调用waitForFinished来等到Message执行完成
//           reply.waitForFinished();

//           if (reply.isValid())
//              {
//                  int value = reply.value();
//                  qDebug() << QString("value =  %1").arg(value);
//              }
//              else
//              {
//                  qDebug() << "value method called failed!";
//              }



    MainWindow w;
    w.show();
    return a.exec();
}
