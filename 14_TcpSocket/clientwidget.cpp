#include "clientwidget.h"
#include "ui_clientwidget.h"
#include<QHostAddress>
ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    setWindowTitle("客户端");
    tcpSocket=NULL;
    tcpSocket=new QTcpSocket(this);
    connect(tcpSocket,&QTcpSocket::connected,[=](){
        ui->textEditRead->setText(QString("连接服务器成功！"));
    });

    connect(tcpSocket,&QTcpSocket::readyRead,[=](){
        QByteArray arr= tcpSocket->readAll();
        ui->textEditRead->append(arr);
    });
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_buttonConnect_clicked()
{

    qint16 port=ui->lineEdit->text().toInt();
    QString ip = ui->lineEdit_2->text();
    tcpSocket->connectToHost(QHostAddress(ip),port);
}

void ClientWidget::on_buttonSend_clicked()
{
    if(!tcpSocket->isOpen())
        return;
    QString str=ui->textEditWrite->toPlainText();
    tcpSocket->write(str.toUtf8().data());
    ui->textEditWrite->clear();
}

void ClientWidget::on_buttonClose_clicked()
{
    if(!tcpSocket->isOpen())
        return;
    tcpSocket->disconnectFromHost();
    tcpSocket->close();

}
