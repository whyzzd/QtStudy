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
    qDebug()<< QSqlDatabase::drivers();

    QSqlDatabase db= QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("test");

    //打开数据库
    if(!db.open())
    {
        QMessageBox::warning(this,"错误",db.lastError().text());
        return ;
    }

    //QSqlQuery query;
    //创建一个表
    //query.exec("create table student(id int primary key auto_increment,name varchar(255),age int,score int)");
    //query.exec("insert into student(id,name,age,score) values(1,'mike',20,23)");
//////////////////////////////////////
    //批量插入
    //odbc风格
    //预处理
    //？相当于占位符
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
//////////////////////////////////////////////
    //oracle风格
    // 占位符:+自定义名字
//    query.prepare("insert into student(name,age,score) values(:name,:age,:score)");
//    QVariantList nameList2;
//    nameList2<<"小明ss"<<"小龙ss"<<"小人ss";
//    QVariantList ageList2;
//    ageList2<<121<<223<<344;
//    QVariantList scoreList2;
//    scoreList2<<903<<883<<366;
//    //给字段绑定
//    query.bindValue(":name",nameList2);
//    query.bindValue(":age",ageList2);
//    query.bindValue(":score",scoreList2);
//    //执行预处理命令
//    query.execBatch();

////oracle风格的优点在于可以不用按照顺序/////////////////
    QSqlQuery query;
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


void Widget::on_delButton_clicked()
{
    QString str = ui->lineEdit->text();

    //删除的sql的语句
    QString sql=QString("delete from student where name = '%1'").arg(str);
    //开启一个事务
    QSqlDatabase::database().transaction();

    QSqlQuery query;
    query.exec(sql);
}

void Widget::on_sureButton_clicked()
{
    //确认删除
    QSqlDatabase::database().transaction();
}

void Widget::on_cancelButton_clicked()
{
    //撤销删除
    QSqlDatabase::database().rollback();

}
