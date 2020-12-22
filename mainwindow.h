#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool copyFolder(const QString &fromDir, const QString &toDir, bool coverFileIfExist); // 拷贝文件函数，参数1：要拷贝的文件目录，参数2：要拷贝到哪个目录，参数3：若有文件，是否覆盖

    //conf 文件相关
    void readConf(); // 解析conf文件
    QSettings *mqsetting;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
