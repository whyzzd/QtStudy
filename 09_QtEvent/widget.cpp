#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    //给label安装事件过滤器
    //步骤一
    ui->label->installEventFilter(this);//this表示谁来给它安装
    //步骤二，重写eventfilter

}
//重写事件过滤器事件
bool Widget::eventFilter(QObject *obj,QEvent*e)
{
    if(obj==ui->label)
    {
        if(e->type()==QEvent::MouseButtonPress)
        {
            QMouseEvent *ev=static_cast<QMouseEvent*>(e);
            QString str=QString("事件过滤鼠标点击事件，x=%1,y=%2").arg(ev->x()).arg(ev->x());
            qDebug()<<str;
            return true;
        }
    }

    return QWidget::eventFilter(obj,e);
}


Widget::~Widget()
{
    delete ui;
}

