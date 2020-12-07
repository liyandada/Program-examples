#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    btn = new QPushButton(this);
    btn->setText("單例");

    connect(btn,&QPushButton::clicked,[=](){
        qDebug()<<"ok";
        testdemo::instance()->showlabel(); //通过此函数实现testdemo单例
    });

}

MainWindow::~MainWindow()
{
}

