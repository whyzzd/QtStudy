#include "filesystem.h"
#include "ui_filesystem.h"
#include<QDebug>
#include<QFile>
#include<QProcess>
#include<QMouseEvent>

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

    ui->treeView->installEventFilter(this);
    this->installEventFilter(this);
    ui->tableView->installEventFilter(this);

}

void FileSystem::init()
{
    QString curPath=QDir::currentPath();
    m_Model=new QFileSystemModel(this);
    m_Model->setRootPath(curPath);

    ui->treeView->setModel(m_Model);
    ui->treeView->header()->resizeSection(0,200);
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
        QFileInfo info(m_Model->filePath(index));
        QString str=info.suffix();

        //图片格式
        QString imgStr("bmp,gif,jpg,jpeg,png,pbm,pgm,ppm,xbm,xpm");
        QStringList  list= imgStr.split(",");
        //文本格式
        QString txtStr="txt,md,docx,rtf,cpp,h";
        QStringList list2=txtStr.split(",");
        if(list.indexOf(str.toLower())!=-1)
        {
            QPixmap pix;
            pix.load(m_Model->filePath(index));
            //图片等比例进行缩放
            pix=pix.scaled(ui->label->width(),ui->label->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
            ui->label->setPixmap(pix);

        }
        else if(txtStr.indexOf(str)!=-1)
        {
            QFile file(path);
            bool ret=file.open(QIODevice::ReadOnly|QIODevice::Text);
            if(!ret)
            {
                qDebug()<<"文件打开失败";
                file.close();
            }
            else
            {
                //QString s=file.readAll();

                ui->label->setText(QString::fromUtf8(file.readAll()));
            }
        }
        else
        {
            ui->label->setText("该文件无法预览");
        }
    }
    else
    {
        ui->label->setText("当前无预览");
    }



}

void FileSystem::on_treeView_doubleClicked(const QModelIndex &index)
{

    if(!m_Model->isDir(index))
    {
        //以子进程的方式打开外部程序，若主进程关闭，则子进程也会关闭
        //QProcess *pros=new QProcess(this);
        //pros->start(m_Model->filePath(index));
        //以阻塞的方式打开程序
        //QProcess::execute(m_Model->filePath(index));

        //以分离的方式打开外部程序,使用以上两种方式无法打开较大的程序
        QProcess::startDetached(m_Model->filePath(index));
    }
    else
    {
        //否则双击进入子目录
        //m_Model->setRootPath(m_Model->filePath(index));

    }
}

void FileSystem::on_listView_doubleClicked(const QModelIndex &index)
{
    if(m_Model->isDir(index))
    {
        ui->listView->setRootIndex(index);

    }

}
static int a=0;
void FileSystem::mouseDoubleClickEvent(QMouseEvent* e)
{
    if(e->button()==Qt::RightButton)
    {
        qDebug()<<"委屈委屈"<<a++;
    }

}
bool FileSystem::eventFilter(QObject *obj, QEvent *event)
{
    if(obj==ui->treeView)
    {
        if(event->type()==QEvent::MouseButtonDblClick)
        {
            QMouseEvent *e=static_cast<QMouseEvent*>(event);
            if(e->buttons()==Qt::RightButton)
            {
                qDebug()<<"已经将右键拦截"<<a++;
                return true;
            }
        }

    }
    else if(obj==this)
    {
        if(event->type()==QEvent::MouseButtonDblClick)
        {
            QMouseEvent *e=static_cast<QMouseEvent*>(event);
            if(e->buttons()==Qt::RightButton)
            {
                qDebug()<<"已经将this的右键拦截";
                return true;
            }
        }
    }
    else if(obj==ui->tableView)
    {
        if(event->type()==QEvent::MouseButtonDblClick)
        {
            QMouseEvent *e=static_cast<QMouseEvent*>(event);
            if(e->buttons()==Qt::RightButton)
            {
                qDebug()<<"已经将tableView的右键拦截";
                return true;
            }
        }
    }

    return false;

}
