#ifndef MYTREEVIEW2_H
#define MYTREEVIEW2_H

#include <QWidget>
#include<QTreeView>
#include<QFileSystemModel>
namespace Ui {
class MyTreeView2;
}

class MyTreeView2 : public QTreeView
{
    Q_OBJECT

public:
    explicit MyTreeView2(QWidget *parent = nullptr);
    ~MyTreeView2();
private slots:
    void on2_double_clicked(const QModelIndex &index);
    void TreeWidgetMenuSlot(const QPoint &);
    void MenuActionSlot(QAction *act);

    void mouseDoubleClickEvent(QMouseEvent *event);


private:
    Ui::MyTreeView2 *ui;
    QFileSystemModel *m_Model;

    QMenu *m_pCustomMenu;
};

#endif // MYTREEVIEW2_H
