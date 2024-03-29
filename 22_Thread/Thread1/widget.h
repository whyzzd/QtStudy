#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTimer>
#include"mythread.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void stopThreadSlots();

private:
    Ui::Widget *ui;
    QTimer *timer;
    MyThread *mythread;
};
#endif // WIDGET_H
