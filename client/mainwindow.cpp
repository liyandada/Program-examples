#include "mainwindow.h"
#include <QDBusConnection>
#include <QDBusReply>
#include <QDBusInterface>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    // 创建QDBusInterface接口
      QDBusInterface interface("com.scorpio.test", "/test/objects",
                               "com.scorpio.test.value",
                               QDBusConnection::sessionBus());
      if (!interface.isValid())
      {
          qDebug() << qPrintable(QDBusConnection::sessionBus().lastError().message());
          exit(1);
      }

      //调用远程的value方法
      QDBusReply<QString> reply = interface.call("value","qwe");
      if (reply.isValid())
      {
          QString value = reply.value();
          qDebug() << QString("value =  %1").arg(value);
      }
      else
      {
          qDebug() << "value method called failed!";
      }

    //监听kkk信号，触发getsignal
    QDBusConnection::sessionBus().connect(QString("com.scorpio.test"), QString("/test/objects"),
                                         QString("com.scorpio.test.value"),
                                         QString("kkk"), this, SLOT(getsignal(QString)));
}

MainWindow::~MainWindow()
{
}


QString MainWindow::getsignal(QString arg)
{
    qDebug()<<"getsignal"<<arg;
}
