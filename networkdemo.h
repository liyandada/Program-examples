#ifndef NETWORKDEMO_H
#define NETWORKDEMO_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QFile>
#include <QNetworkRequest>
#include <QNetworkReply>

class NetWorkAccessManager : public QNetworkAccessManager
{
    Q_OBJECT
public:
    explicit NetWorkAccessManager(QObject *parent = nullptr);
    QString download(QString url, QString path);
    QString filePath;
    QNetworkReply *netReply;
    void waitForFinished();
    QFile *fileMap;

signals:
void finisheDown();
void canread();
public slots:
void downloadchange(int x,int y);
};

#endif // NETWORKDEMO_H
