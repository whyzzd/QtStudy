#include "clientwidget.h"
#include "ui_clientwidget.h"
#include<QHostAddress>
ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    tcpsocket=NULL;
    tcpsocket=new QTcpSocket(this);

    //从tcpsocket当中读取
    connect(tcpsocket,&QTcpSocket::readyRead,[=](){
        QByteArray strread=tcpsocket->readAll();
        ui->textEditread->append(strread);
    });

}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_Buttonconnect_clicked()
{
    //获取服务器端口及ip
    qint16 port=ui->lineEdit->text().toInt();
    QString ip=ui->lineEdit_2->text();

    tcpsocket->connectToHost(QHostAddress(ip),port);

    //提示客户端已经连接到服务器,当连接上服务器之后会自动触发connected
    connect(tcpsocket,&QTcpSocket::connected,[=](){
        ui->textEditread->setText("成功连接到服务器");
    });

}

void ClientWidget::on_Buttonsnd_clicked()
{
    if(tcpsocket==NULL)
        return;
    //获取文字
    QString str=ui->textEditwrite->toPlainText();

    //往套接字里面写文字
    tcpsocket->write(str.toUtf8().data());


}

void ClientWidget::on_Buttonclose_clicked()
{
    if(tcpsocket==NULL)
    {
        return;
    }

    tcpsocket->disconnectFromHost();
    tcpsocket->close();

    tcpsocket=NULL;
}
