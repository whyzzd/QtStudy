#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);

private:
    Ui::Widget *ui;
    //每一个方格的高度和宽度
    int one_width;
    int one_height;


    //求棋盘的范围
    int leftwid=width()/10;
    int rightwid=width()-width()/10;
    int topheight=height()/10;
    int bottomheight=height()-height()/10;

    //画棋子的点
    QPoint drawPoint;
};
#endif // WIDGET_H
