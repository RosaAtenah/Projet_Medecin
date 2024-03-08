#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Gestionnaire de base de données");
    //instance effet
    opacityEffect=new QGraphicsOpacityEffect(this);
    //application effet
    ui->label_3->setGraphicsEffect(opacityEffect);
    //lier effet a l'animation
    fadeAnimation.setTargetObject(opacityEffect);
    fadeAnimation.setPropertyName("opacity");
    fadeAnimation.setStartValue(1.0);
    fadeAnimation.setEndValue(0.0);
    fadeAnimation.setDuration(3000);
    connect(&fadeAnimation,&QPropertyAnimation::finished,this,&MainWindow::changeImage);
    fadeAnimation.start();
    changeImage();
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    quit=new Quit(this);
    connect(quit, &Quit::closeMainWindow,this,&MainWindow::close);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text()=="Holy" && ui->lineEdit_2->text()=="123456"){
        ui->label_3->setText("Login réussi");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    this->lower();
    this->setVisible(false);
    quit->raise();
    quit->setVisible(true);
}
void MainWindow::changeImage(){
    if(currentImageIndex>=(int)(this->img).size()){
        currentImageIndex=0;
    }
    QPixmap pixmap(img[currentImageIndex]);
    ui->label_3->setPixmap(pixmap);
    opacityEffect->setOpacity(1.0);
    fadeAnimation.start();
    currentImageIndex++;
}

void MainWindow::on_pushButton_4_clicked()
{
    if(clicktest%2==1){
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
        ui->label_4->setText("not view");
    }
    else{
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
        ui->label_4->setText("view");
    }
    clicktest++;
}

