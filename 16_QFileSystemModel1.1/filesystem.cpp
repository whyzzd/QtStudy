#include "filesystem.h"
#include "ui_filesystem.h"
#include<QDebug>
#include<QMovie>
FileSystem::FileSystem(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FileSystem)
{
    ui->setupUi(this);

    setWindowTitle("Mac的文件目录浏览器");
    this->resize(1000,600);
    init();
    connect(ui->treeView,&QTreeView::clicked,ui->tableView,&QTableView::setRootIndex);
    connect(ui->columnView,&QColumnView::clicked,ui->listView,&QListView::setRootIndex);

    //QLabel *showCont=

}

void FileSystem::init()
{
    QString curPath=QDir::currentPath();
    m_Model=new QFileSystemModel;
    m_Model->setRootPath(curPath);
    qDebug()<<"---"<<curPath<<"----";
    ui->treeView->setModel(m_Model);
    ui->tableView->setModel(m_Model);
    ui->columnView->setModel(m_Model);
    ui->listView->setModel(m_Model);

    m_FileName=new QLabel("文件名/文件夹名:",ui->statusbar);
    m_FileName->setMinimumWidth(200);
    m_FileSize=new QLabel("文件大小:",ui->statusbar);
    m_FileSize->setMinimumWidth(200);
    m_FileType=new QLabel("文件类型:",ui->statusbar);
    m_FileType->setMinimumWidth(200);
    m_FilePath=new QLabel("文件路径:",ui->statusbar);
    m_FilePath->setMinimumWidth(300);

    ui->statusbar->addWidget(m_FileName);
    ui->statusbar->addWidget(m_FileSize);
    ui->statusbar->addWidget(m_FileType);
    ui->statusbar->addWidget(m_FilePath);
}
FileSystem::~FileSystem()
{
    delete ui;
}


void FileSystem::on_treeView_clicked(const QModelIndex &index)
{
    QString name=m_Model->fileName(index);
    m_FileName->setText("文件名/文件夹名:"+name);

    qint64 size=m_Model->size(index);
    m_FileSize->setText("文件大小:"+QString::number(size)+"B");

    QString type=m_Model->type(index);
    m_FileType->setText("文件类型:"+type);

    QString path=m_Model->filePath(index);
    m_FilePath->setText("文件路径:"+path);
    if(!m_Model->isDir(index))
    {
        //QPixmap pix;
       //pix.load(m_Model->filePath(index));
        //ui->label->setPixmap(pix);

        QMovie *mov=new QMovie(m_Model->filePath(index));
        mov->start();
        ui->label->setScaledContents(true);
        ui->label->setMovie(mov);



    }

}
