#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QPixmap>
#include<QImage>
#include<QPicture>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    //Pixmap绘图设备 在Pixmap上绘图，然后保存到磁盘中
//    //Pixmap绘图设备 专门为平台做了显示的优化
//    QPixmap pix(200,200);
//    QPainter painter(&pix);
//    QPen pen(Qt::red);
//    painter.setPen(pen);
//    //设置填充色
//    pix.fill();
//    //开始画内容
//    painter.drawEllipse(QPoint(100,100),50,50);
//    pix.save("D:/aaa.png");
      //--------------------------------------------------------------
    //QImage 绘图设备 用法可以和Pixmap一样，它还可以对像素进行访问
//    QImage img(300,300,QImage::Format_A2BGR30_Premultiplied);
//    QPainter painter(&img);
//    img.fill(Qt::green);
//    painter.setPen(QPen(qRgb(255,0,0)));
//    painter.drawRect(100,100,100,100);
//    img.save("D:/bbb.jpg");
    //----------------------------------------------------------------
    //QPicture 绘图设备 可以记录和重新显示绘图指令
//    QPicture pic;
//    QPainter painter;
//    painter.setPen(qRgb(255,0,0));
//    //开始往pic上画
//    painter.begin(&pic);
//    painter.drawEllipse(100,100,100,100);
//    //结束画画
//    painter.end();
//    //将画的画进行保存
//    pic.save("D:/ddd.wyf");


}
void Widget::paintEvent(QPaintEvent *)
{
    //利用QImage 对像素进行操作
    QImage img;
    QPainter painter(this);


    img.load(":/Image/aaa.jpg");
    img=img.scaled(200,200);//易错点，需要刷新一下，注意注意注意！！！！！！！！！
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            //像素点类型的值
            QRgb value=qRgb(255,0,0);
            img.setPixel(50,50,value);
        }
    }
    painter.drawImage(0,0,img);

    //--------------------------------------------------------------------
    //利用Qpicture将wyf文件加载出来
//    QPicture pic;
//    pic.load("D:/ddd.wyf");
//    QPainter painter(this);
//    painter.drawPicture(0,0,pic);
}
Widget::~Widget()
{
    delete ui;
}

