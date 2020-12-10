#include "networkdemo.h"
#include <QDebug>
#include <QEventLoop>

NetWorkAccessManager::NetWorkAccessManager(QObject *parent) : QNetworkAccessManager(parent)
{

}

QString NetWorkAccessManager::download(QString url,QString path) {
    qDebug()<<"url:"<<url;
    qDebug()<<"path:"<<path;
    QNetworkRequest request(url);
    filePath = path;
    qDebug()<<url;
    netReply = get(request);
    connect(netReply,&QNetworkReply::downloadProgress,this,&NetWorkAccessManager::downloadchange);

    connect(netReply,&QNetworkReply::readyRead, [this] () {
        fileMap = new QFile(filePath);
        if(fileMap->exists()) {
            fileMap->remove();
        }

        if(fileMap->open(QIODevice::WriteOnly) == false) {
            qDebug() << "Open file failed!";
        } else {

//            qDebug()<<"netReply"<<netReply->readAll();
            fileMap->write(netReply->readAll());
            qDebug()<< fileMap->flush();
            fileMap->close();
            emit finisheDown();

        }
    });
    return path;
}

void NetWorkAccessManager::downloadchange(int x,int y)
{
    qDebug()<<"downloadchange:"<<y;
}
