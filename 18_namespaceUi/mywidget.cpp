#include "mywidget.h"
#include<QDebug>
//QT_BEGIN_NAMESPACE
MyWidget::MyWidget()
{
    qDebug()<<"这是mywidget中的构造";

}
void MyWidget::fun()
{
    qDebug()<<"这是myWidget中的fun函数";

}


//QT_END_NAMESPACE
