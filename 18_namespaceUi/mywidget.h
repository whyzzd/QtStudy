#ifndef MYWIDGET_H
#define MYWIDGET_H


class MyWidget
{
public:
    MyWidget();
    void fun();
};
namespace Ui{
    class Widget:public MyWidget{};
}

#endif // MYWIDGET_H
