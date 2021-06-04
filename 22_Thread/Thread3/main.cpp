#include "widget.h"

#include <QApplication>
#include"threadimage.h"
#include<QTime>
int main(int argc, char *argv[])
{
    //生成随机数种子
    qsrand(QTime::currentTime().msec());
    QApplication a(argc, argv);
    Widget w;

    w.show();
    ThreadImage aa;
    return a.exec();
}
