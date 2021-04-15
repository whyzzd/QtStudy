#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QTimer>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击按钮来移动图片
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        this->m_Num+=100;
        update();//如果手动来调用画图事件 使用update来更新
    });

    //使用计时器来移动图片
    QTimer *timer=new QTimer(this);
    timer->start(500);
    connect(timer,&QTimer::timeout,[=](){
        m_Num+=50;
        update();
    });//易错点第一个对象要用地址

    connect(timer,&QTimer::timeout,[=](){
        static int n=1;
        ui->label->setText(QString::number(n++));
    });
    //注意事项：Qtimer对象必须要在堆上创建才能有效果
}

//绘图事件
void Widget::paintEvent(QPaintEvent *)
{
//    //实例化画家对象 this 指定的是绘图设备
//    QPainter pain(this);

//    //设置画笔
//    QPen pen(QColor(255,0,0));

//    pen.setWidth(3);
//    pen.setStyle(Qt::DotLine);
//    //画家设置画笔
//    pain.setPen(pen);

//    //设置画刷
//    QBrush bru(QColor(0,255,0));
//    bru.setStyle(Qt::Dense3Pattern);
//    //画家设置画刷
//    pain.setBrush(bru);

//    //画线
//    pain.drawLine(0,0,200,200);

//    //画圆
//    pain.drawEllipse(QPoint(200,200),50,50);

//    //画椭圆
//    pain.drawEllipse(QPoint(100,100),20,10);

//    //画矩形
//    pain.drawRect(400,400,100,50);

//    //画文字
//    pain.drawText(QRect(20,500,100,20),"新年快乐");


    ///////////////////////高级设置/////////////////////////////
//    QPainter painter(this);

//    painter.drawEllipse(100,50,100,100);
//    //设置 抗锯齿能力 效率较低
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(200,50,100,100);

    //画矩形
//    painter.drawRect(100,200,50,50);

//    //将画家移动
//    painter.translate(100,0);

//    painter.drawRect(100,200,50,50);
//    //保存画家的状态
//    painter.save();

//    painter.translate(100,0);

//    //可以将画家还原
//    painter.restore();
//    painter.drawRect(100,200,50,50);


/////////////////利用画家 画出资源文件///////////////////////////
    QPainter painter(this);
    if(m_Num>this->width())
    {
        m_Num=0;
    }
    painter.drawPixmap(m_Num,0,200,200,QPixmap(":/Image/aaa.jpg"));


}

Widget::~Widget()
{
    delete ui;
}

