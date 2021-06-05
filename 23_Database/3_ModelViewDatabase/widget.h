#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QSqlTableModel>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_addButton_clicked();

    void on_sureButton_clicked();

    void on_cancelButton_clicked();

    void on_delButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QSqlTableModel *model;
};
#endif // WIDGET_H
