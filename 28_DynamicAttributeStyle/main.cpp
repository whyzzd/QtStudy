
#include "widget.h"

#include <QApplication>
#include<QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    QFile styleFile(":/styles.qss"); // Load the QSS file
    styleFile.open(QFile::ReadOnly | QFile::Text);
    QString styleSheet = styleFile.readAll();
    a.setStyleSheet(styleSheet);

    w.show();
    return a.exec();
}
