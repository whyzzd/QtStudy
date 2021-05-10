#include "serverwidget.h"
#include "ui_serverwidget.h"

ServerWidget::ServerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerWidget)
{
    ui->setupUi(this);

    setWindowTitle("服务器:8888");
    tcpServer=NULL;
    tcpSocket=NULL;
    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any,8888);

    connect(tcpServer,&QTcpServer::newConnection,[=](){
        tcpSocket=tcpServer->nextPendingConnection();
        QString ip = tcpSocket->peerAddress().toString();
        qint16 port = tcpSocket->peerPort();

        QString str=QString("[%1:%2]:连接成功").arg(ip).arg(port);
        ui->textEditRead->setText(str);

        connect(tcpSocket,&QTcpSocket::readyRead,[=](){
            QByteArray arr =tcpSocket->readAll();
            ui->textEditRead->append(arr);
        });


    });
}

ServerWidget::~ServerWidget()
{
    delete ui;
}


void ServerWidget::on_buttonSend_clicked()
{
    if(tcpSocket==NULL)
    {
        return;
    }
    QString str=ui->textEditWrite->toPlainText();
    tcpSocket->write(str.toUtf8().data());
    ui->textEditWrite->clear();
}

void ServerWidget::on_buttonClose_clicked()
{
    if(tcpSocket==NULL)
        return;
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    tcpSocket=NULL;
}
