#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    thread = new QThread(this);

    //不能给自己创的线程类指定父对象，否则它将不在子线程执行
    myt= new MyThread;

    //将对象移动至子线程中
    myt->moveToThread(thread);

    connect(myt,&MyThread::changesignal,this,&Widget::dislcd);
    qDebug()<<"主线程号："<<QThread::currentThread();

    connect(this,&Widget::startmyt,myt,&MyThread::mytimeout);


    //如果强制推出(即在开启线程之后直接关闭窗口)
    connect(this,&Widget::destroyed,this,[=](){
        on_stopButton_clicked();
        delete myt;
    });

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_startButton_clicked()
{
    //注意，还要开启子线程
    if(thread->isRunning())return;
    thread->start();
    myt->settoclose(false);
    emit startmyt();


}

void Widget::on_stopButton_clicked()
{
    if(!thread->isRunning())return;
    myt->settoclose(true);
    thread->quit();
    thread->wait();

}
void Widget::dislcd()
{
    static int a=0;
    a++;
    ui->lcdNumber->display(a);


}
