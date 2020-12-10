#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QUrl url();
      NWAMaganer = new NetWorkAccessManager;
      //第一个参数为下载地址，第二个参数为下载文件路径
      NWAMaganer->download("https://mirrors.aliyun.com/ubuntu/pool/restricted/i/iucode-tool/iucode-tool_1.5.1-1.debian.tar.xz","/home/li/Program-xamples/Program-xamples/iucode-tool_1.5.1-1.debian.tar.xz");
}

MainWindow::~MainWindow()
{
}

