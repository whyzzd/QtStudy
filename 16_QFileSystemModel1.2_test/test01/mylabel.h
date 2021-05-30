#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>

namespace Ui {
class MyLabel;
}

class MyLabel : public QWidget
{
    Q_OBJECT

public:
    explicit MyLabel(QWidget *parent = nullptr);
    ~MyLabel();

private slots:
    void mouseDoubleClickEvent(QMouseEvent *);
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::MyLabel *ui;
};

#endif // MYLABEL_H
