#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //将值设置为一半
    connect(ui->btn_setNum,&QPushButton::clicked,[=](){
        ui->widget->setNum(50);
    });
    //获取值并打印
    connect(ui->btn_getNum,&QPushButton::clicked,[=](){
        qDebug()<<ui->widget->getNum();
    });
}

Widget::~Widget()
{
    delete ui;
}

