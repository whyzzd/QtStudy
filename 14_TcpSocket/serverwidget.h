#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include<QTcpServer>//监听套接字
#include<QTcpSocket>//通信套接字


QT_BEGIN_NAMESPACE
namespace Ui { class ServerWidget; }
QT_END_NAMESPACE

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    ServerWidget(QWidget *parent = nullptr);
    ~ServerWidget();

private slots:
    void on_ButtonSend_clicked();

    void on_ButtonClose_clicked();

private:
    Ui::ServerWidget *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
};
#endif // SERVERWIDGET_H
