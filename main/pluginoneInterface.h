#ifndef PLUGINONEINTERFACE_H
#define PLUGINONEINTERFACE_H
#include <QWidget>
#include <QPushButton>

class pluginoneinterface
{
public:
    virtual ~pluginoneinterface() {}
    virtual QPushButton *onewidget(QWidget *parent) = 0;              //获取快捷操作面板的界面
};
#define pluginoneinterface_iid "org.ukui.sidebar-qt.plugin-iface.shortCutPanelInterface"
Q_DECLARE_INTERFACE(pluginoneinterface, pluginoneinterface_iid)

#endif // PLUGINONEINTERFACE_H
