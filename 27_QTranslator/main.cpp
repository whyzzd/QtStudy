
#include "widget.h"

#include <QApplication>
#include<QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QTranslator translator;           //定义翻译器变量
//    if (translator.load("TestCN.qm"))   //加载翻译文件
//    {
//        a.installTranslator(&translator); //安装翻译器
//    }

    Widget w;
    w.show();
    return a.exec();
}
