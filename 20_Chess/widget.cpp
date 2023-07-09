#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QMouseEvent>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //初始化棋子坐标
    drawPoint.setX(-1);
    drawPoint.setY(-1);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    one_width=width()/10;
    one_height=height()/10;
    leftwid=width()/10;
    rightwid=width()-width()/10;
    topheight=height()/10;
    bottomheight=height()-height()/10;


    QPainter painter;
    QPen pen;
    pen.setWidth(4);
    painter.begin(this);
    //注意：若在begin之前写会造成setpen无效
    painter.setPen(pen);
    for(int i=0;i<9;i++)
    {

        //画竖线
        painter.drawLine(one_width+i*one_width,one_height,one_width+i*one_width,one_height+8*one_height);
        //画横线
        painter.drawLine(one_width,one_height+i*one_height,one_width+8*one_height,one_width+i*one_width);
    }
    if(drawPoint.rx()!=-1&&drawPoint.ry()!=-1)
    {
        painter.drawPixmap(drawPoint.rx(),drawPoint.ry(), one_width,one_height,QPixmap("../20_Chess/a.png"));
    }


    painter.end();
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    int x=event->x();
    int y=event->y();
    if(x>=leftwid&&x<=rightwid&&y>=topheight&&y<=bottomheight)
    {
        drawPoint.setX(x-x%one_width);
        drawPoint.setY(y-y%one_height);

        //更新窗口
        update();
    }


}
