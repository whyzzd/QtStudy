#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);

    connect(timer,&QTimer::timeout,[=](){
        static int a=0;
        a++;
        ui->lcdNumber->display(a);
    });
    mythread=new MyThread(this);
    //注意：此处第三个参数如果不写会提示，timer无法被其它线程killed
//    connect(mythread,&MyThread::sstop,this,[=](){
//        timer->stop();
//    });

    connect(mythread,&MyThread::sstop,this,&Widget::stopThreadSlots,Qt::QueuedConnection);

    connect(this,&Widget::destroyed,[=](){
        mythread->quit();
    });
}
Widget::~Widget()
{
    delete ui;
}
void Widget::on_pushButton_clicked()
{

    if(!timer->isActive())
    {
        timer->start(200);
    }

    //线程开始处理(不要直接调用run)
    mythread->start();
}

void Widget::on_pushButton_2_clicked()
{
    timer->stop();
}

void Widget::stopThreadSlots()
{
    timer->stop();
}
