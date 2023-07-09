#include "mywidget.h"
#include "ui_mywidget.h"
#include<QString>
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);


}

MyWidget::~MyWidget()
{
    delete ui;
}
void MyWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    //QModelIndex index = indexA
    //if(!m_Model->isDir(index))
    {
        //以子进程的方式打开外部程序，若主进程关闭，则子进程也会关闭
        //QProcess *pros=new QProcess(this);
        //pros->start(m_Model->filePath(index));
        //以阻塞的方式打开程序
        //QProcess::execute(m_Model->filePath(index));

        //以分离的方式打开外部程序,使用以上两种方式无法打开较大的程序

        //QProcess::startDetached(m_Model->filePath(index));
    }
    //else
    {
        //否则双击进入子目录
        //m_Model->setRootPath(m_Model->filePath(index));

    }
}
