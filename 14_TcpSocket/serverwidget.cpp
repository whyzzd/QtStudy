#include "serverwidget.h"
#include "ui_serverwidget.h"

ServerWidget::ServerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerWidget)
{
    ui->setupUi(this);
    tcpSocket=NULL;
    tcpServer=NULL;
    tcpServer =new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any,8888);

    setWindowTitle("服务器：8888");


    connect(tcpServer,&QTcpServer::newConnection,[=](){
        //取出建立好链接的套接字
        tcpSocket=tcpServer->nextPendingConnection();

        //获取对方的ip端口
        QString ip=tcpSocket->peerAddress().toString();
        qint16 port = tcpSocket->peerPort();

        QString temp=QString("[%1：%2]:成功连接").arg(ip).arg(port);

        ui->textEditRead->setText(temp);

        //读取消息
        connect(tcpSocket,&QTcpSocket::readyRead,[=](){
            QByteArray array = tcpSocket->readAll();
            ui->textEditRead->append(array);
        });
    });
}

ServerWidget::~ServerWidget()
{
    delete ui;
}


void ServerWidget::on_ButtonSend_clicked()
{
    if(tcpSocket==NULL)
    return;
    //获取编辑区的内容
    QString str=ui->textEditWrite->toPlainText();
    //给对方发送数据
    tcpSocket->write(str.toUtf8().data());
}

void ServerWidget::on_ButtonClose_clicked()
{
    if(tcpSocket==NULL)
    return;
    tcpSocket->disconnectFromHost();
    tcpSocket->close();

    tcpSocket=NULL;
}
