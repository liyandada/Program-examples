#ifndef THREADADDLG_H
#define THREADADDLG_H

#include <QPushButton>
#include <QHBoxLayout>
#include <QDialog>
#include <workthread.h>
#define MAXSIZE 3
class threadaddlg : public QDialog
{
    Q_OBJECT
public:
    threadaddlg(QWidget *parent = nullptr);


private:

    QPushButton *startBtn;
    QPushButton *stopBtn;
    QPushButton *quitBtn;
    QHBoxLayout *mainlayout1;

    workthread *workThread[MAXSIZE];


public slots:
    void slotstatrt();
    void slotstop();




};

#endif // THREADADDLG_H
