#include "mylabel.h"
#include<QDebug>

myLabel::myLabel(QWidget *parent) : QLabel(parent)
{
    //设置鼠标的追踪状态，不用点击即可输出
    setMouseTracking(true);
}
//鼠标进入事件
void myLabel::enterEvent(QEvent *event)
{
   // qDebug()<<"鼠标进入了";
}

//鼠标离开事件
void myLabel::leaveEvent(QEvent *event)
{
    //qDebug()<<"鼠标退出了";
}
//鼠标在label中移动
 void myLabel::mouseMoveEvent(QMouseEvent *ev)
{
    //qDebug()<<"鼠标移动了";
    //仅适用左键移动来控制输出
     if(ev->buttons()&Qt::LeftButton)
     {
         QString str=QString("左键移动鼠标时,x=%1,y=%2").arg(ev->x()).arg(ev->y());
         qDebug()<<str;
     }
}

//鼠标在label中按压,在label中能找到QMouseEvent
void myLabel::mousePressEvent(QMouseEvent *ev)
{
    //使用QString 函数格式来输出坐标
    QString str=QString("鼠标按下了x=%1  y=%2").arg(ev->x()).arg(ev->y());
    qDebug()<<str;

}
//鼠标在label中释放
void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    //qDebug()<<"鼠标释放了";
    QString str=QString("鼠标释放了x=%1  y=%2").arg(ev->x()).arg(ev->y());
    qDebug()<<str;
}

//在event中对鼠标按下进行拦截
bool myLabel::event(QEvent *e)
{
    //如果是鼠标按下，在event事件分发中做拦截操作
    if(e->type()==QEvent::MouseButtonPress)
    {
        QMouseEvent *ev=static_cast<QMouseEvent*>(e);
        QString str=QString("对鼠标进行拦截，x=%1,y=%2").arg(ev->x()).arg(ev->y());
        qDebug()<<str;
        return true;//true表示用户自己处理这个时间，不向下分发
    }

    //其它事件 交给父类默认处理
    return QLabel::event(e);
}
