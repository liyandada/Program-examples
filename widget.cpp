#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //设置任务栏无显示
    setWindowFlags(Qt::FramelessWindowHint | Qt::X11BypassWindowManagerHint);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    QDesktopWidget *deskdop=QApplication::desktop();
    this->move((deskdop->width()-this->width())/2, (deskdop->height()-this->height())/2);
    this->setFixedSize(500,250);
    this->setAttribute(Qt::WA_TranslucentBackground);
    initUI();
}

Widget::~Widget()
{

}
void Widget::initUI()
{
    m_pmainlayout = new QVBoxLayout();
    m_pfirstlayout = new QHBoxLayout();
    m_ptestlayout = new QVBoxLayout();
    buttonlayout = new QHBoxLayout();
    m_pleftIconlayout = new QVBoxLayout();
    m_pcenterlayout = new QHBoxLayout();

    topWidget = new QWidget();
    iconLabel = new QLabel();
    contentWidget = new QWidget();

    QImage *img=new QImage; //新建一个image对象
    img->load(":/new/prefix1/system-update.png"); //将图像资源载入对象img，注意路径，可点进图片右键复制路径
    iconLabel->setPixmap(QPixmap::fromImage(*img)); //将图片放入label，使用setPixmap,注意指针*img

    topLabel = new QLabel();
    topLabel->setText("系统升级");

    linebutton = new QPushButton();
    linebutton->setMaximumSize(500,1);
    linebutton->setFocusPolicy(Qt::NoFocus);

    firstlabel = new QLabel();
    seclabel   = new QLabel();
    firstlabel->setText("系统更新已准备就绪，请重启安装最新版本");
    seclabel->setText("请注意保存您的文件");

    remindButton = new QPushButton();
    remindButton->setText("30分钟后提醒我");
    remindButton->setFixedSize(160,40);
    remindButton->setStyleSheet("background-color: rgb(255,255,255);color:black;border:1px solid grey;border-radius:10px;");
    connect(remindButton,&QPushButton::clicked,this,&Widget::remindslots);

    restartButton = new QPushButton();
    restartButton->setText("立即重启");
    restartButton->setFixedSize(160,40);
    restartButton->setStyleSheet("background-color: rgb(85,173,222);color:white;");
    connect(restartButton,&QPushButton::clicked,this,&Widget::restartslots);
    buttonWidget = new QWidget();

    iconBigLabel = new QLabel();
    QImage *img1=new QImage; //新建一个image对象
    img1->load(":/new/prefix1/system-updatepig.png"); //将图像资源载入对象img，注意路径，可点进图片右键复制路径
    iconBigLabel->setPixmap(QPixmap::fromImage(*img1)); //将图片放入label，使用setPixmap,注意指针*img
    leftIconWidget = new QWidget();
    centerWidget = new QWidget();

    //标题布局
    m_pfirstlayout->addWidget(iconLabel);
    m_pfirstlayout->addWidget(topLabel);
    m_pfirstlayout->addItem(new QSpacerItem(500,2));
    topWidget->setLayout(m_pfirstlayout);

    //按钮布局
    buttonlayout->addWidget(remindButton);
    buttonlayout->addWidget(restartButton);
    buttonWidget->setLayout(buttonlayout);

    //左侧图标布局
    m_pleftIconlayout->addWidget(iconBigLabel);
    m_pleftIconlayout->addItem(new QSpacerItem(2,250));
    leftIconWidget->setFixedWidth(70);
    leftIconWidget->setLayout(m_pleftIconlayout);

    //右侧文字主体内容布局
    m_ptestlayout->addWidget(firstlabel);
    m_ptestlayout->addWidget(seclabel);
    m_ptestlayout->addItem(new QSpacerItem(2,20));
    m_ptestlayout->addWidget(buttonWidget);
    contentWidget->setLayout(m_ptestlayout);

    //增加图标主体内容布局
    m_pcenterlayout->addWidget(leftIconWidget);
    m_pcenterlayout->addWidget(contentWidget);
    centerWidget->setLayout(m_pcenterlayout);

    //整体布局
    m_pmainlayout->addWidget(topWidget);
    m_pmainlayout->addWidget(linebutton);
    m_pmainlayout->addWidget(centerWidget);

    this->setLayout(m_pmainlayout);
}

void Widget::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    /* 获取当前剪贴板中字体的颜色，作为背景色；
     * 白字体 --> 黑背景
     * 黑字体 --> 白字体
    */
    p.setBrush(opt.palette.color(QPalette::Base));
    p.setOpacity(1);
    p.setPen(QPen(QColor(255,255,255)));
    QPainterPath path;
    opt.rect.adjust(0,0,0,0);
    path.addRoundedRect(opt.rect,16,16);
    p.setRenderHint(QPainter::Antialiasing);                        //反锯齿
    p.drawRoundedRect(opt.rect,16,16);
    setProperty("blurRegion",QRegion(path.toFillPolygon().toPolygon()));
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}

void Widget::remindslots()
{
    qDebug()<<"remindslots";

}
void Widget::restartslots()
{
    qDebug()<<"restartslots";
}
