
#include "widget.h"
#include "ui_widget.h"

#include<QComboBox>
#include<QTranslator>
#include<QDebug>
QTranslator *translator=new QTranslator;

void Trans(int index)
{
         //定义翻译器变量

    QApplication::removeTranslator(translator);

    QString file;
    if(index==0)
    {
        file="TestCN.qm";
        qDebug()<<"testcn";
    }
    else if(index==1)
    {
        file="TestENG.qm";
        qDebug()<<"testEng";
    }
    if (translator->load(file))   //加载翻译文件
    {

        QApplication::installTranslator(translator); //安装翻译器
    }

}


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->comboBox->setCurrentIndex(1);
    connect(ui->comboBox,QOverload<int>::of(&QComboBox::currentIndexChanged),this,[](int index){
        Trans(index);

        qDebug()<<"index:"<<index;
    });
}

void Widget::changeEvent(QEvent* e)
{
    QWidget::changeEvent(e);
    if (e->type() == QEvent::LanguageChange) {
        //retranslateUi();
        ui->retranslateUi(this);
    }
}

Widget::~Widget()
{
    delete ui;
}


