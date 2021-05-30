#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
namespace Ui{
    class Widget;
}
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    virtual void fun();
private:
    Ui::Widget *ui;
};








/////////////////////////////////////////////
class WidgetSon:public Widget
{
public:
    WidgetSon(QWidget *parent = nullptr);
    ~WidgetSon();
    void fun();
};

#endif // WIDGET_H
