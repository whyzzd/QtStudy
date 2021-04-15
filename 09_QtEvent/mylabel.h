#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include<QEvent>
#include<QMouseEvent>
class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);

    //鼠标进入事件
    void enterEvent(QEvent *event);

    //鼠标离开事件
    void leaveEvent(QEvent *event);


    //鼠标在label中移动
    virtual void mouseMoveEvent(QMouseEvent *ev) override;
    //鼠标在label中按压
    virtual void mousePressEvent(QMouseEvent *ev) override;
    //鼠标在label中释放
    virtual void mouseReleaseEvent(QMouseEvent *ev) override;

    //在event中对鼠标按下进行拦截
    bool event(QEvent *e);

signals:

};

#endif // MYLABEL_H
