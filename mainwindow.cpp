#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    p=new threadaddlg(this);
    p->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

