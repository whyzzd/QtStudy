#include "mytreeview2.h"
#include "ui_mytreeview2.h"
#include<QProcess>
#include<QMouseEvent>
#include<QDebug>
#include<QMenu>
MyTreeView2::MyTreeView2(QWidget *parent) :
    QTreeView(parent),
    ui(new Ui::MyTreeView2)
{
    ui->setupUi(this);
    QString str=QDir::currentPath();
    m_Model=new QFileSystemModel(this);
    m_Model->setRootPath(str);
    ui->treeView->setModel(m_Model);

    ui->treeView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->treeView, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(TreeWidgetMenuSlot(const QPoint &)));

    //connect(ui->treeView,&QTreeView::doubleClicked,this,&MyTreeView2::on2_double_clicked);


}
MyTreeView2::~MyTreeView2()
{
    delete ui;
}

void MyTreeView2::on2_double_clicked(const QModelIndex &index)
{
    if(!m_Model->isDir(index))
    {
        qDebug()<<m_Model->fileName(index).toUtf8().data();
        QProcess::startDetached(m_Model->filePath(index));
    }

}
void MyTreeView2::mouseDoubleClickEvent(QMouseEvent *event)
{
    QModelIndex index = ui->treeView->currentIndex();
    if(event->button()==Qt::LeftButton)
    {
        if(!m_Model->isDir(index))
        {
            QProcess::startDetached(m_Model->filePath(index));
        }
    }
}

void MyTreeView2::TreeWidgetMenuSlot(const QPoint &)
{
    QModelIndex index = ui->treeView->currentIndex();
if(!m_Model->isDir(index))
{
    m_pCustomMenu = new QMenu(this);
    connect(m_pCustomMenu, SIGNAL(triggered(QAction *)), this, SLOT(MenuActionSlot(QAction *)));

    m_pCustomMenu->clear();
    QAction *act1 = new QAction(tr("灯"), m_pCustomMenu);
    act1->setData(1);
    m_pCustomMenu->addAction(act1);

    QAction *act2 = new QAction(tr("红"), m_pCustomMenu);
    act2->setData(2);
    m_pCustomMenu->addAction(act2);

    QAction *act3 = new QAction(tr("酒"), m_pCustomMenu);
    act3->setData(3);
    m_pCustomMenu->addAction(act3);

    QAction *act4 = new QAction(tr("绿"), m_pCustomMenu);
    act4->setData(4);
    m_pCustomMenu->addAction(act4);

    m_pCustomMenu->popup(QCursor::pos());
}
}

void MyTreeView2::MenuActionSlot(QAction *act)
{
    if (act == NULL)
        {
            return;
        }
        int nData = act->data().toInt();
        switch (nData)
        {
        case 1:
            qDebug() << "好花好景好时光";
            break;
        case 2:
            qDebug() << "画堂春暖不胜香";
            break;
        case 3:
            qDebug() << "红裙舞动燕飞忙";
            break;
        case 4:
            qDebug() << "一片行云到画堂";
            break;
        default:
            break;
        }
}
