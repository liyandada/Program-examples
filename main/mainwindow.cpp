#include "mainwindow.h"
#include <QDir>
#include <QCoreApplication>
#include <QPluginLoader>
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    m_pMainQVBoxLayout = new QVBoxLayout();
    if(loadQuickOperationPlugin()){
        qDebug()<<"yes";
    } else {
        qDebug()<<"no";
    }
//    QPushButton *bbb = new QPushButton();
//    m_pMainQVBoxLayout->addWidget(bbb);


    this->setLayout(m_pMainQVBoxLayout);
}

MainWindow::~MainWindow()
{
}

bool MainWindow::loadQuickOperationPlugin()
{
    //判断是否安装进系统
    QDir pluginsDir;
    static bool installed = (QCoreApplication::applicationDirPath() == QDir(("/usr/bin")).canonicalPath());

    if (installed){
        pluginsDir = QDir("/usr/bin");
    } else {
        qDebug()<<"检测没安装";
        pluginsDir = QDir(qApp->applicationDirPath() + "/../pluginone");
    }

    pluginsDir.setFilter(QDir::Files);
    QPluginLoader pluginLoader(pluginsDir.absoluteFilePath("libPlugin1.so"));
    QObject *pPlugin = pluginLoader.instance();
    if (pPlugin == nullptr)
        return false;

    m_pShortCutPanelInterface = dynamic_cast<pluginoneinterface *>(pPlugin);
    QPushButton* shortCutWidget = m_pShortCutPanelInterface->onewidget(this);
//    shortCutWidget->show();
    m_pMainQVBoxLayout->addWidget(shortCutWidget);

    return true;
}

