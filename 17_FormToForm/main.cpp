#include "gooneform.h"
#include"gotwoform.h"
#include"gothreeform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GoOneForm::init();
    GoTwoForm::init();
    GoThreeForm::init();
    GoOneForm::oneform->show();

    return a.exec();
}
