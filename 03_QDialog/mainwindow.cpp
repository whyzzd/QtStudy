#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDialog>
#include<QDebug>
#include<QMessageBox>
#include<QColorDialog>
#include<QFileDialog>
#include<QString>
#include<QFontDialog>
#include<QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //单机新建按钮弹出对话框
    connect(ui->actionnew,&QAction::triggered,[=](){
        //对话框分为两种
        //模态对话框（不可以对其他窗口进行操作），非模态对话框（可以对其他窗口进行操作）
        //1.模态创建
//        QDialog dig(this);
//        dig.resize(300,200);
//        dig.exec();
//        qDebug()<<"模态对话框已经弹出"<<endl;

        //2.非模态创建
//        QDialog dig2(this);
//        dig2.show();//使用show函数创建非模态
//        dig2.resize(300,200);
//        dig2.exec();
        //2.1在堆区创建非模态
//        QDialog *dig3 =new QDialog(this);
//        dig3->resize(300,200);
//        dig3->show();
//        qDebug()<<"非模态创建完成"<<endl;
//        //但是堆区的数据需要进行释放
//        dig3->setAttribute(Qt::WA_DeleteOnClose);

        //消息对话框的创建
        //错误对话框
        //QMessageBox::critical(this,"critical","错误");

        //信息对话框
        //QMessageBox::information(this,"infor","信息");

        //提问对话框
        //参数一 父亲，参数二 标题 ，参数三 提示内容 ，参数四 按键类型 ，参数五 默认关联回车键
//        if(QMessageBox::Save==QMessageBox::question(this,"ques","提问",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel))
//        {
//            qDebug()<<"选择的是保存"<<endl;
//        }
//        else
//        {
//            qDebug()<<"选择的是取消"<<endl;
//        }
        //警告对话框
        QMessageBox::warning(this,"warning","警告");

        //其它标准对话框
        //颜色对话框
        //QColor qc=QColorDialog::getColor(QColor(255,0,0));
        //qDebug()<<"r="<<qc.red()<<" "<<"g="<<qc.green()<<" "<<"b="<<qc.blue();

        //文件对话框 参数一 父亲，参数二 标题，参数三 默认打开路径 参数四 过滤文件格式
        //QString str=QFileDialog::getOpenFileName(this,"文件对话框","C:\\Users\\WYF\\Desktop","*.txt");
        //qDebug()<<"文件的路径是："<<str<<endl;

        //字体对话框
        bool flag;
        QFont font=QFontDialog::getFont(&flag,QFont("华文彩云",36));
        qDebug()<<"字体："<<font.family().toUtf8().data()<<" "<<"字号"<<font.pointSize()<<"是否加粗："<<font.bold()<<"是否倾斜"<<font.italic();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

