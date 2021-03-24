#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QApplication>
#include <QDesktopWidget>
#include <QPainter>
#include <QStyleOption>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QHBoxLayout  *m_pfirstlayout    = nullptr;
    QVBoxLayout  *m_pmainlayout     = nullptr;
    QVBoxLayout  *m_ptestlayout     = nullptr;
    QHBoxLayout  *buttonlayout      = nullptr;
    QVBoxLayout  *m_pleftIconlayout = nullptr;
    QHBoxLayout  *m_pcenterlayout     = nullptr;

    QWidget *topWidget;
    QWidget *contentWidget;
    QWidget *buttonWidget;
    QWidget *leftIconWidget;
    QWidget *centerWidget;

    QLabel *iconLabel;
    QLabel *topLabel;

    QPushButton *linebutton;

    QLabel *firstlabel;
    QLabel *seclabel;

    QPushButton *remindButton;
    QPushButton *restartButton;

    QLabel *iconBigLabel;

    void initUI();
    void paintEvent(QPaintEvent *e);

protected slots:
    void remindslots();
    void restartslots();
};
#endif // WIDGET_H
