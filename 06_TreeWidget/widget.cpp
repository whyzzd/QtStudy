#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList()<<"属性"<<"属性介绍"<<"附加说明");

    //设置顶部节点
    QTreeWidgetItem *gongItem=new QTreeWidgetItem(QStringList()<<"攻击");
    ui->treeWidget->addTopLevelItem(gongItem);
    //追加子节点
    QTreeWidgetItem *wuyingjian=new QTreeWidgetItem(QStringList()<<"无影剑"<<"攻击时附加30%的伤害"<<"当阻挡它的同时已经受到伤害");
    QTreeWidgetItem *yingren=new QTreeWidgetItem(QStringList()<<"影刃"<<"攻速增加40%"<<"快快快");
    gongItem->addChild(wuyingjian);
    gongItem->addChild(yingren);

    QTreeWidgetItem *fangItem=new QTreeWidgetItem(QStringList()<<"防御");
    //追加顶部节点
    ui->treeWidget->addTopLevelItem(fangItem);
    QStringList sl;
    sl<<"炎麟护肩"<<"增加一亿点防御"<<"无";
    QTreeWidgetItem *yanlin=new QTreeWidgetItem(sl);
    //追加子节点
    fangItem->addChild(yanlin);
}

Widget::~Widget()
{
    delete ui;
}

