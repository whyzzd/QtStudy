#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include<QTcpSocket>
namespace Ui {
class ClientWidget;
}

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWidget(QWidget *parent = nullptr);
    ~ClientWidget();

private slots:
    void on_Buttonconnect_clicked();

    void on_Buttonsnd_clicked();

    void on_Buttonclose_clicked();

private:
    Ui::ClientWidget *ui;
    QTcpSocket *tcpsocket;
};

#endif // CLIENTWIDGET_H
