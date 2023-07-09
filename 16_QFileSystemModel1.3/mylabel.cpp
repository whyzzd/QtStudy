#include "mylabel.h"
#include "ui_mylabel.h"
#include<QMouseEvent>
#include<QDebug>
#include"mywidget.h"
MyLabel::MyLabel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyLabel)
{
    ui->setupUi(this);
    ui->pushButton->installEventFilter(this);
    this->installEventFilter(this);


}

MyLabel::~MyLabel()
{
    delete ui;
}
void MyLabel::mouseDoubleClickEvent(QMouseEvent *e)
{
    //if(e->buttons()==Qt::LeftButton)
    {
        qDebug()<<"sdasdadsa";
    }


}
bool MyLabel::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==ui->pushButton)
    {
        if(event->type()==QEvent::MouseButtonDblClick)
        {
            QMouseEvent *e=static_cast<QMouseEvent*>(event);
            if(e->buttons()==Qt::LeftButton)
            {
                qDebug()<<"sssss";
                return true;
            }
        }

    }
    else if(watched==this)
    {
        if(event->type()==QEvent::MouseButtonDblClick)
        {
            QMouseEvent *e=static_cast<QMouseEvent*>(event);
            if(e->buttons()==Qt::RightButton)
            {
                qDebug()<<"已经将右键拦截";
                return true;
            }
        }
    }
    return false;
}

