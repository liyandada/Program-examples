#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTextBrowser>
#include <QXmlStreamReader>
#include <QDomElement>
#include <QDomDocument>
#include <QStringList>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void  fileButtonClick();
    QVBoxLayout *m_mainlayout = nullptr;
    QHBoxLayout *m_pathlayout = nullptr;
    QWidget *m_pathWidget;
    QLineEdit   * pathEdit;
    QPushButton *btn;
    QTextBrowser *xmlAnalysis;

    QStringList chinese_result;
    QStringList pinyin_result;

    QString index1;
    QString index;
    QString index2;
    QString allData;

    QMap<QString,QStringList> pinyin_searchlist;
    QMap<QString,QStringList> chine_searchlist;

    void readxml(QString path);
    void settexttovrowser(QMap<QString,QStringList> pinyin,QMap<QString,QStringList> chinese);


};
#endif // MAINWINDOW_H
