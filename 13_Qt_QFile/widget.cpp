#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>
#include<QFile>
#include<QDebug>
#include<QFileInfo>
#include<QDateTime>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString path=QFileDialog::getOpenFileName(this,"打开文件","C:\\Users\\WYF\\Desktop");
        //将文件显示在单行编辑框中
        ui->lineEdit->setText(path);

        //创建文件对象,QFile默认支持的格式是utf-8
        QFile file(path);//参数就是文件的路径
        //打开的方式
        file.open(QIODevice::ReadOnly);
        QByteArray str=file.readAll();
        ui->textEdit->setText(str);

        file.close();
        //对文件进行写的操作
//        file.open(QIODevice::Append);
//        file.write("qweqweqweqwe");
//        file.close();

        //利用FileInfo来读取文件信息
        QFileInfo info(path);
        qDebug()<<"大小："<<info.size()<<"后缀名："<<info.suffix()<<"文件名称："<<info.fileName();
        qDebug()<<"创建日期："<<info.created().toString("yyyy.MM.dd hh:mm:ss");
        qDebug()<<"最后修改日期："<<info.lastModified().toString("yyyy.MM.dd hh:mm:ss");
    });
}

Widget::~Widget()
{
    delete ui;
}

