#include "widget.h"
#include "ui_widget.h"
#include<QSqlDatabase>
#include<QDebug>
#include<QMessageBox>
#include<QSqlError>
#include<QSqlQuery>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //打印qt支持的数据库
    qDebug()<<QSqlDatabase::drivers();
    //添加sqlite数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库
    db.setDatabaseName("../student.db");
    if(!db.open())
    {
        QMessageBox::warning(this,"错误",db.lastError().text());
        return;
    }
    QSqlQuery query;
//    query.exec("create table student(id int primary key,name varchar(255),age int,score int)");
//    query.prepare("insert into student(name,age,score) values(?,?,?)");
//    QVariantList nameList;
//    nameList<<"小明"<<"小龙"<<"小人";
//    QVariantList ageList;
//    ageList<<11<<23<<44;
//    QVariantList scoreList;
//    scoreList<<90<<88<<66;

//    //给字段绑定相应的值;
//    query.addBindValue(nameList);
//    query.addBindValue(ageList);
//    query.addBindValue(scoreList);
//    //执行批处理命令
//    query.execBatch();

    query.exec("select * from student");
    while(query.next())
    {
        //取出当前行内容
        //value中的参数也可直接使用字段名
        qDebug()<<query.value(0).toInt()
                <<query.value(1).toString()
                <<query.value(2).toInt()
                <<query.value(3).toInt();


    }
}

Widget::~Widget()
{
    delete ui;
}

