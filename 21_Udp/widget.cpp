#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    udpSocket=new QUdpSocket(this);
    udpSocket->bind(8888);
    setWindowTitle("服务器端口号：8888");

    connect(udpSocket,&QUdpSocket::readyRead,this,[=](){
        char buf[1024]={0};
        QHostAddress ip;
        quint16 port;

        udpSocket->readDatagram(buf,sizeof(buf),&ip,&port);
        QString str=QString("[%1 %2]:%3").arg(ip.toString()).arg(port).arg(buf);
        ui->textEdit->setText(str);
    });

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_sendButton_clicked()
{
    //疑问，类型之间的转换的问题
    QString ip=ui->lineEdit->text();
    quint16 port= ui->lineEdit_2->text().toInt();
    QString str=ui->textEdit->toPlainText();



    udpSocket->writeDatagram(str.toUtf8(),QHostAddress(ip),port);
}

void Widget::on_closeButton_clicked()
{
    udpSocket->close();

}
