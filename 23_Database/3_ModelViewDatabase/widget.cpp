#include "widget.h"
#include "ui_widget.h"
#include<QSqlDatabase>
#include<QDebug>
#include<QMessageBox>
#include<QSqlError>
#include<QTreeView>
#include<QSqlRecord>
#include<QSqlQueryModel>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    ui->setupUi(this);
    qDebug()<< QSqlDatabase::drivers();
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("test");

    //打开数据库
    if(!db.open())
    {
        QMessageBox::warning(this,"错误",db.lastError().text());
        return;
    }

    //设置模型
    model=new QSqlTableModel(this);
    model->setTable("student");
    //显示model的数据
    model->select();

    //显示model中的数据
    ui->tableView->setModel(model);

    model->setHeaderData(0,Qt::Horizontal,"学号");

    //设置model的编辑模式，手动提交修改
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    //设置为不可编辑
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QSqlQueryModel *model11=new QSqlQueryModel(this);
    model11->setQuery("select name from student");
    ui->comboBox->setModel(model11);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_addButton_clicked()
{
    QSqlRecord record=model->record();
    //qDebug()<<record.count();
    int row = model->rowCount();
    model->insertRecord(row,record);
}

void Widget::on_sureButton_clicked()
{
    model->submitAll();
}

void Widget::on_cancelButton_clicked()
{
    model->revertAll();//取消所有动作
    model->submitAll();
}

void Widget::on_delButton_clicked()
{
    //选中的模型
    QItemSelectionModel *sModel = ui->tableView->selectionModel();
    QModelIndexList list=sModel->selectedRows();

    //if(!list.isEmpty())
    //model->removeRows(list[0].row(),list.size());

    for(int i=0;i<list.size();i++)
    {
        model->removeRow(list.at(0).row());
    }
}

void Widget::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    QString str=QString("name='%1'").arg(name);
    //相当于select *from student where name='' 只用写后面的语句
    model->setFilter(str);
    model->select();
}
