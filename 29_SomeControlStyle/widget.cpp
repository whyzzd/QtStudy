
#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(1200,800);
    //ui->pushButton->setDisabled(true);

    QString str=":/image/switch_off.png";

    setWindowIcon(QIcon(str));
}

Widget::~Widget()
{
    delete ui;
}


