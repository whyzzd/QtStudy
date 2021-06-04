#include "threadimage.h"
#include<QPainter>
#include<QPen>
#include<QBrush>
#include<QDebug>
#include<QThread>
ThreadImage::ThreadImage(QObject *parent) : QObject(parent)
{

}
void ThreadImage::drawImage()
{
    QImage image(500,500,QImage::Format_ARGB32);
    //构造函数不显示？试试删了重来
    QPainter painter(&image);

    QPen pen;
    pen.setWidth(2);
    pen.setColor(QColor(Qt::red));

    QBrush bru;
    bru.setColor(Qt::blue);
    bru.setStyle(Qt::SolidPattern);


    QPoint p[5]={};
    for(int i=0;i<5;i++)
    {
        p[i]=QPoint(qrand()%300,qrand()%300);

    }
    //注意：如果是写成这种形式，那么setpen和setbrush要写在里面
    //painter.begin(&image);
    painter.setPen(pen);
    painter.setBrush(bru);
    painter.drawPolygon(p,5);
    //painter.end();

    emit sendimage(image);
    qDebug()<<"子线程："<<QThread::currentThread();

}
