#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QThread>
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
signals:
    void startmyt();

private slots:
    void on_startButton_clicked();

    void on_stopButton_clicked();

    void dislcd();

private:
    Ui::Widget *ui;

    QThread *thread;
    MyThread *myt;

};
#endif // WIDGET_H
