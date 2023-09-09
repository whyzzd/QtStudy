
#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
#include<QFile>
#include<QVBoxLayout>
#include<QStyle>
#include"mypushbutton.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    MyPushButton *button1=new MyPushButton/*("Button 1",this)*/;
//    button1->setText("Button 1");
//    button1->setParent(this);
//    button1->setProperty("styleClass", "myButton"); // Style class for button 1
//    //button1->setObjectName("myButton");
//    //button1->setStyleSheet("#myButton{background-color: green;}");

//    MyPushButton *button2=new MyPushButton/*("Button 2",this)*/;
//    button2->setText("Button 2");
//    button2->setParent(this);
//    button2->setProperty("flat", "true"); // Style class for button 2flat="false"
//    //button2->setObjectName("myButton");
//    //button2.show();
//    QVBoxLayout *layout=new QVBoxLayout;
//    layout->addWidget(button1);
//    layout->addWidget(button2);
//    setLayout(layout);

    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        ui->label->setProperty("value","red");
        ui->label->style()->unpolish(ui->label);
        ui->label->style()->polish(ui->label);
        ui->label->update();
        ui->label->setText("red");
    });
    connect(ui->pushButton_2,&QPushButton::clicked,this,[=](){
        ui->label->setProperty("value","green");
        ui->label->style()->unpolish(ui->label);
        ui->label->style()->polish(ui->label);
        ui->label->update();
        ui->label->setText("green");
    });
    connect(ui->pushButton_3,&QPushButton::clicked,this,[=](){
        ui->label->setProperty("value","blue");
        ui->label->style()->unpolish(ui->label);
        ui->label->style()->polish(ui->label);
        ui->label->update();
        ui->label->setText("blue");
    });
    connect(ui->pushButton_4,&QPushButton::clicked,this,[=](){
        ui->label->setProperty("value","orange");
        ui->label->style()->unpolish(ui->label);
        ui->label->style()->polish(ui->label);
        ui->label->update();
        ui->label->setText("orange");
    });
    connect(ui->pushButton_5,&QPushButton::clicked,this,[=](){
        ui->label->setProperty("value","yellow");
        ui->label->style()->unpolish(ui->label);
        ui->label->style()->polish(ui->label);
        ui->label->update();
        ui->label->setText("yellow");
    });

}

Widget::~Widget()
{
    delete ui;
}


