#include "widget.h"
#include "ui_widget.h"
#include<QTimer>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_Id1=startTimer(1000);
    //开始计时器返回的是计时器的id号
    m_Id2=startTimer((2000));

    //使用第二种方式使用定时器
    QTimer *timer=new QTimer(this);//指定一个爸爸
    timer->start(500);
    connect(timer,&QTimer::timeout,[=](){
        static int num=1;
        ui->label_3->setText(QString::number(num++));
    });

    //可以使用一个按钮让计时器暂停
    connect(ui->btn_Stop,&QPushButton::clicked,[=](){
        timer->stop();
    });
    //让计时器继续进行
    connect(ui->btn_Start,&QPushButton::clicked,[=](){
       timer->start();
    });
}

//重写计时器函数
void Widget::timerEvent(QTimerEvent *ev)
{
    if(this->m_Id1==ev->timerId())
    {
        static int num1=1;
        ui->label->setText(QString::number(num1++));
    }
    else
    {
        static int num2=1;
        ui->label_2->setText(QString::number(num2++));
    }
}
Widget::~Widget()
{
    delete ui;
}

