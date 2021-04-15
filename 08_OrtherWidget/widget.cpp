#include "widget.h"
#include "ui_widget.h"
#include<QMovie>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->btn_Scroll,&QPushButton::clicked,[=](){
        //设置stackedWidget的显示页
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->btn_Tab,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->btn_Toll,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    //下拉框添加数据
    ui->comboBox->addItem("小汽车");
    ui->comboBox->addItem("拖拉机");
    ui->comboBox->addItem("大卡车");
    connect(ui->btn_Select,&QPushButton::clicked,[=](){
        //ui->comboBox->setCurrentIndex(1);
        //或者
        ui->comboBox->setCurrentText("拖拉机");
    });

    //利用QLabel来显示图片
    ui->lbl_Image->setPixmap(QPixmap(":/Camera Roll/bbb.jpg"));
    ui->lbl_Image->setScaledContents(true);

    //利用Q
    QMovie *mov=new QMovie(":/Camera Roll/giphy.gif");
    ui->lbl_Movie->setMovie(mov);
    ui->lbl_Movie->setScaledContents(true);
    //播放动图
    mov->start();
}

Widget::~Widget()
{
    delete ui;
}

