#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <QMainWindow>
#include "quit.h"
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QGraphicsOpacityEffect>
#include <QtSql/QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int clicktest=1;
    std::vector<QString> img={"../Qt_img/images/logo.JPG","../Qt_img/images/login1.jpg","../Qt_img/images/login2.jpg"};
    QGraphicsOpacityEffect* opacityEffect;
    int currentImageIndex=0;
    QPropertyAnimation fadeAnimation;
    Quit* quit;
    void changeImage();
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
