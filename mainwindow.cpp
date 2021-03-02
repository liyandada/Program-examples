#include "mainwindow.h"

#define XML_Source QString::fromLocal8Bit("ChineseFunc")
#define XML_Title  QString::fromLocal8Bit("ChinesePlugin")

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    m_mainlayout = new QVBoxLayout(this);
    m_pathlayout = new QHBoxLayout(this);
    pathEdit = new QLineEdit();
    m_pathWidget = new QWidget();
    btn = new QPushButton();
    btn->setText("选择要解析的xml");
    connect(btn,&QPushButton::clicked,this,&MainWindow::fileButtonClick);

    xmlAnalysis = new QTextBrowser();
    xmlAnalysis->setFixedSize(560,500);


    m_pathlayout->addWidget(pathEdit);
    m_pathlayout->addWidget(btn);
    m_pathWidget->setLayout(m_pathlayout);

    m_mainlayout->addWidget(m_pathWidget);
    m_mainlayout->addWidget(xmlAnalysis);

    this->setFixedSize(600,600);
    this->setLayout(m_mainlayout);


}

MainWindow::~MainWindow()
{

}

void MainWindow::fileButtonClick()
{
    QString path = QFileDialog::getOpenFileName(this,"选择文件","./","*.xml");
    if (!path.isEmpty()) {
        pathEdit->setText(path);
        readxml(path);
    }
}
void MainWindow::readxml(QString path)
{
     qDebug()<<path;
     QFile file(QString::fromLocal8Bit(path.toUtf8()));
     if (!file.open(QIODevice::ReadOnly)){
         return;
     }

     QDomDocument doc;
     doc.setContent(&file);
     QDomElement root=doc.documentElement();
     QDomNode node = root.previousSibling();
     node=root.firstChild();
     QString sameornot;

     //循环遍历整个xml文件进行解析
     while(!node.isNull()){
         QDomElement element=node.toElement();
         QString key =element.attribute("name");
         if(sameornot != key){
             sameornot = element.attribute("name");
             pinyin_result.clear();
             chinese_result.clear();
         }
         QDomNodeList list=element.childNodes();
         for(int i=0;i<list.count();++i){
             QDomNode n=list.at(i);
             if(n.nodeName()==QString::fromLocal8Bit("pinyinPlugin")){
                 index1=n.toElement().text();
             }
             if(n.nodeName()==QString::fromLocal8Bit("pinyinfunc")){
                 index1+=QString::fromLocal8Bit(":")+n.toElement().text();
//                 qDebug()<<index1;
                 pinyin_result.append(index1);
             }

             if(n.nodeName()==QString::fromLocal8Bit("ChinesePlugin")){
                 index=n.toElement().text();
             }
             if(n.nodeName()==QString::fromLocal8Bit("ChineseFunc")){
                 index+=QString::fromLocal8Bit(":")+n.toElement().text();

             chinese_result.append(index);
             }
         }

         pinyin_searchlist.insert(key,pinyin_result);
         chine_searchlist.insert(key,chinese_result);

         node=node.nextSibling();
     }
     file.close();
     settexttovrowser(pinyin_searchlist,chine_searchlist);

}

void MainWindow::settexttovrowser(QMap<QString,QStringList> pinyin,QMap<QString,QStringList> chinese)
{
    xmlAnalysis->clear();
    QMap<QString, QStringList>::iterator i;
    for ( i = pinyin.begin(); i != pinyin.end(); ++i ) {
    qDebug()<< i.key();
    qDebug()<< pinyin.value(i.key());
    allData.append(i.key());
    allData.append("\n");
    for(int j = 0;j<pinyin.value(i.key()).count();j++){
        allData.append(pinyin.value(i.key()).at(j));
        allData.append(" ");
    }
    allData.append("\n");


    }

    for ( i = chinese.begin(); i != chinese.end(); ++i ) {
    qDebug()<< i.key();
    qDebug()<< chinese.value(i.key());
    allData.append(i.key());
    allData.append("\n");
//    allData.append(chinese.value(i.key()));
    for(int j = 0;j<chinese.value(i.key()).count();j++){
        allData.append(chinese.value(i.key()).at(j));
        allData.append(" ");
    }
        allData.append("\n");
    }

    xmlAnalysis->setText(allData);




}
