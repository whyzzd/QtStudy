#include "widget.h"
#include<QDebug>

//包含MyWidget的头
#include"mywidget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),ui(new Ui::Widget)
{
    qDebug()<<"widget的构造函数";
    ui->fun();

}
Widget::~Widget()
{
}
void Widget::fun()
{
    qDebug()<<"Widget的fun";
}



////////////////////////////////////////////////////
WidgetSon::WidgetSon(QWidget *parent)
    :Widget(parent)
{
    qDebug()<<"WidgetSon构造函数";

}
WidgetSon::~WidgetSon()
{
}
void WidgetSon::fun()
{
    qDebug()<<"WidgetSon的fun";
}
