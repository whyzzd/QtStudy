#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QPainter>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    thread=new QThread(this);
    //不能给下面指定父对象
    threadimage=new ThreadImage;

    threadimage->moveToThread(thread);
    //由于线程只需要开启一次，然后关闭窗口时关闭，所以直接在构造函数里面进行开启即可
    thread->start();
    qDebug()<<"主线程："<<QThread::currentThread();
    connect(ui->pushButton,&QPushButton::pressed,threadimage,&ThreadImage::drawImage);

    //使用函数指针的形式表示
    void(ThreadImage::*sendimagep)(QImage)=&ThreadImage::sendimage;
    connect(threadimage,sendimagep,this,&Widget::recImage);

    //关闭线程
    connect(this,&Widget::destroyed,this,&Widget::distor);



}
Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawImage(100,100,m_image);
}


void Widget::on_pushButton_clicked()
{


}
void Widget::recImage(QImage m)
{
    update();
    m_image=m;

}
void Widget::distor()
{
    thread->quit();
    thread->wait();
    delete threadimage;
}
