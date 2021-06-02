#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include<QUdpSocket>
namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();

private slots:
    void on_sendButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::Client *ui;
    QUdpSocket *udpsocket;
};

#endif // CLIENT_H
