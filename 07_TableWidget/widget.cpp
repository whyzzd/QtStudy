#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //TableWidget控件
    //设置列数
    ui->tableWidget->setColumnCount(3);
    //设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");
    //设置行数
    ui->tableWidget->setRowCount(5);

    //设置正文内容
    //ui->tableWidget->setItem(0,0,new QTableWidgetItem("刘备"));
    QStringList nameList;
    nameList<<"刘备"<<"关羽"<<"张飞"<<"赵云"<<"安琪拉";
    QList<QString> sexList;
    sexList<<"男"<<"男"<<"男"<<"男"<<"女";

    for(int i=0;i<5;i++)
    {
      int count=0;
      ui->tableWidget->setItem(i,count++,new QTableWidgetItem(nameList[i])) ;
      ui->tableWidget->setItem(i,count++,new QTableWidgetItem(sexList.at(i))) ;
      ui->tableWidget->setItem(i,count++,new QTableWidgetItem(QString::number(18+i))) ;
    }
}

Widget::~Widget()
{
    delete ui;
}

