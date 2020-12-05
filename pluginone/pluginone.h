#ifndef PLUGINONE_H
#define PLUGINONE_H

#include <QObject>
#include "../main/pluginoneInterface.h"
#include <QPushButton>
#include <QWidget>
#include <QDebug>
#include <QVBoxLayout>

class pluginone : public QObject, public pluginoneinterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.ukui.sidebar-qt.plugin-iface.shortCutPanelInterface" FILE "pluginone.json")
    Q_INTERFACES(pluginoneinterface)
public:
    explicit pluginone(QObject *parent = nullptr);

    //插件接口
    QPushButton *onewidget(QWidget *parent) override;
    QPushButton   *btn;
    QWidget       *m_pMainWidget     = nullptr;
    QVBoxLayout   *m_pMainLayout    = nullptr;
};

#endif // PLUGINONE_H
