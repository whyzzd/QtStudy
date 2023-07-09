#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QPixmap>
#include<QMouseEvent>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //去窗口边框
    setWindowFlags(Qt::FramelessWindowHint|windowFlags());

    //将背景变得透明
    setAttribute(Qt::WA_TranslucentBackground);


}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *event)
{

    QPainter p;
    p.begin(this);
    p.drawPixmap(0,0,width(),height(), QPixmap("../19_Shape/a1.png"));//注意此处的相对路径的写法
    p.end();
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::RightButton)
    {
        this->close();
    }
    else if(event->button()==Qt::LeftButton)
    {
        p=event->globalPos()-this->frameGeometry().topLeft();
    }
}
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
    {
        //此处需要减p是因为，当窗口移动至鼠标的位置时，是左上角到了鼠标位置，而我们的想要的效果是移动前 鼠标所点击的位置 到 鼠标移动后的位置
        move(event->globalPos()-p);
    }

}
