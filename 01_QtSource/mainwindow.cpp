#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->actionnew->setIcon(QIcon("C:\\Users\\WYF\\Pictures\\Camera Roll\\n6r6m7.jpg"));
    //添加Resource,右键项目添加文件
    //使用添加Qt资源  ":"+"前缀"+"文件名"
    ui->actionopen->setIcon(QIcon(":/Camera Roll/aaa.jpg"));
    ui->actionnew->setIcon(QIcon(":/Camera Roll/bbb.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

