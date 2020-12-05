#include "pluginone.h"

pluginone::pluginone(QObject *parent)
{
//    m_pMainWidget = new QWidget;
//    m_pMainLayout = new QVBoxLayout();
//    btn = new QPushButton();
//    btn->setText("hello");
//    m_pMainLayout->addWidget(btn);
//    m_pMainWidget->setLayout(m_pMainLayout);

}


QPushButton* pluginone::onewidget(QWidget *parent)
{
    qDebug()<<"QPushButton";
    btn = new QPushButton(parent);
    btn->setText("hello");
    return btn;

}


