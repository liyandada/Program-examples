#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pluginoneInterface.h"
#include <QDebug>
#include <QVBoxLayout>
#include <QPushButton>
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    pluginoneinterface*     m_pShortCutPanelInterface;      //插件接口

    bool loadQuickOperationPlugin();                        //加载插件
    QVBoxLayout* m_pMainQVBoxLayout;
    QPushButton *bbb;
};
#endif // MAINWINDOW_H
