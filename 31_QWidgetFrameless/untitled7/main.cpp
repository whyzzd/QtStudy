#include "widget.h"

#include <QApplication>

#include<QWidget>
int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_Use96Dpi);
    QApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::RoundPreferFloor);
    //控制图片缩放质量
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QApplication a(argc, argv);
    Widget w;
    w.show();

    QWidget *ww=new QWidget(&w);
    ww->show();

    return a.exec();
}
