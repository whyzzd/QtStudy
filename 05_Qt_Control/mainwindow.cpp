#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QListWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置单选按钮 默认选中
//    ui->rBtnMan->setChecked(true);
//    connect(ui->rBtnWoman,&QRadioButton::clicked,[=](){
//        qDebug()<<"选中了女"<<endl;
//    });

    ui->cBtnGood->setChecked(true);
    //多选按钮 2是选中 0是取消选中
    connect(ui->cBtnLow,&QCheckBox::stateChanged,[=](int stat){
        qDebug()<<stat;
    });

    //利用listWidget写诗
//    QListWidgetItem *item=new QListWidgetItem("锄禾日当午");
//    //将这一行诗放进控件中
//    ui->listWidget->addItem(item);
//    //设置诗的布局
//    item->setTextAlignment(Qt::AlignHCenter);

    //还可以使用QStringList 相当于QList<QString>
    QStringList list;
    list<<"锄禾日当午"<<"汗滴禾下土"<<"谁知盘中餐"<<"粒粒皆辛苦";
    ui->listWidget->addItems(list);
}

MainWindow::~MainWindow()
{
    delete ui;
}

