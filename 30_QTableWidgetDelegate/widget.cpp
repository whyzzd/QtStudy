#include "widget.h"
#include "ui_widget.h"

#include"spinboxdelegate.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //ui->tableView->setItemDelegate(2,)
     //this->setFixedSize(sizeHint());
    //ui->verticalLayout->setSpacing(30);
    //ui->verticalLayout->addStretch();
    SpinBoxDelegate *spinBoxDelegate=new SpinBoxDelegate;
    ui->tableWidget->setItemDelegateForColumn(1,spinBoxDelegate);
}

Widget::~Widget()
{
    delete ui;
}

