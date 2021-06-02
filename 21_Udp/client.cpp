#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);


    udpsocket=new QUdpSocket(this);
#if 0
    udpsocket->bind(9999);
#else
    //如果是组播，那么不能像上面那样进行绑定了
    udpsocket->bind(QHostAddress::AnyIPv4,9999);
    udpsocket->joinMulticastGroup(QHostAddress("224.0.0.1"));
#endif
    connect(udpsocket,&QUdpSocket::readyRead,[=](){
        QHostAddress ip;
        quint16 port;
        char buf[1024]={0};
        udpsocket->readDatagram(buf,sizeof(buf),&ip,&port);
        QString str=QString("[%1 %2]:%3").arg(ip.toString()).arg(port).arg(buf);
        ui->textEdit->setText(str);
    });
}

Client::~Client()
{
    delete ui;
}

void Client::on_sendButton_clicked()
{
    QString ip=ui->lineEdit->text();
    quint16 port=ui->lineEdit_2->text().toInt();
    QString str=ui->textEdit->toPlainText();

    udpsocket->writeDatagram(str.toUtf8(),QHostAddress(ip),port);
}

void Client::on_closeButton_clicked()
{
    udpsocket->close();
}
