#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QDebug>
#include <QFile>
#include <QFileInfoList>
#include <QTextCodec>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QString fromDir = "/var/lib/kylin-software-properties/kylin-update-timer/";
//    QString toDir = QDir::homePath();
//    toDir += "/.config/kylin-update-manager/";
//    qDebug()<<copyFolder(fromDir,toDir,true);
    readConf();

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::copyFolder(const QString &fromDir, const QString &toDir, bool coverFileIfExist)
{
    QDir sourceDir(fromDir);
    QDir targetDir(toDir);
    if(!targetDir.exists()){    /**< 如果目标目录不存在，则进行创建 */
        if(!targetDir.mkdir(targetDir.absolutePath()))
            return false;
    }

    QFileInfoList fileInfoList = sourceDir.entryInfoList();
    foreach(QFileInfo fileInfo, fileInfoList){
        if(fileInfo.fileName() == "." || fileInfo.fileName() == "..")
            continue;

        if(fileInfo.isDir()){    /**< 当为目录时，递归的进行copy */
            if(!copyFolder(fileInfo.filePath(),
                targetDir.filePath("kylin-update-manager.conf"),
                coverFileIfExist))
                return false;
        }
        else{            /**< 当允许覆盖操作时，将旧文件进行删除操作 */
            if(coverFileIfExist && targetDir.exists("kylin-update-manager.conf")){
                targetDir.remove("kylin-update-manager.conf");
            }

            /// 进行文件copy
            if(!QFile::copy(fileInfo.filePath(),
                targetDir.filePath("kylin-update-manager.conf"))){
                    return false;
            }
            qDebug()<<fileInfo.filePath();
            qDebug()<<targetDir.filePath("kylin-update-manager.conf");
        }
    }
    return true;

}
void MainWindow::readConf()
{
    QString toDir = QDir::homePath();
    toDir += "/.config/kylin-update-manager/kylin-update-manager.conf";
    mqsetting = new QSettings(toDir,QSettings::IniFormat);
    mqsetting->setIniCodec(QTextCodec::codecForName("UTF-8")); //在此添加设置，即可读写conf文件中的中文


    //开始组Generic
    mqsetting->beginGroup(QString::fromLocal8Bit("Generic"));
    //读取
    qDebug()<<mqsetting->value("service").toString();
    qDebug()<<mqsetting->value("prefix").toString();
    qDebug()<<mqsetting->value("enable").toString();
    //写入
//    mqsetting->setValue("service","qwrewqr");
    //结束组
    mqsetting->endGroup();



    //开始组T1
    mqsetting->beginGroup(QString::fromLocal8Bit("T1"));
    //读取
    qDebug()<<mqsetting->value("offsettime").toString();
    //写入
//    mqsetting->setValue("offsettime","qwrewqr");
    //结束组
    mqsetting->endGroup();


}

