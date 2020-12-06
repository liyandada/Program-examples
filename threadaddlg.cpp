#include "threadaddlg.h"

threadaddlg::threadaddlg(QWidget *parent) : QDialog(parent)
{

    setWindowTitle("线程");
    startBtn =new QPushButton(tr("开始"));
    stopBtn =new QPushButton("停止");
    quitBtn =new QPushButton("退出");


    mainlayout1=new QHBoxLayout(this);
    mainlayout1->addWidget(startBtn);
    mainlayout1->addWidget(stopBtn);
    mainlayout1->addWidget(quitBtn);

    connect(startBtn,SIGNAL(clicked()),this,SLOT(slotstatrt()));
    connect(stopBtn,SIGNAL(clicked()),this,SLOT(slotstop()));
    connect(quitBtn,SIGNAL(clicked()),this,SLOT(close()));

}

void threadaddlg::slotstatrt()
{
    for(int i=0;i<MAXSIZE;i++)
    {
        workThread[i]=new workthread();

    }
    for(int i=0;i<MAXSIZE;i++)
    {
        workThread[i]->start();

    }
    startBtn->setEnabled(false);
    stopBtn->setEnabled(true);


}
void threadaddlg::slotstop()
{
    for(int i=0;i<MAXSIZE;i++)
    {
        workThread[i]->terminate();
         workThread[i]->wait();
    }

    startBtn->setEnabled(true);
    stopBtn->setEnabled(false);
}
