#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    enum eDir{
        NONE,
        BOTTOMRIGHT,
        TOPRIGHT,
        TOPLEFT,
        BOTTOMLEFT,
        DOWN,
        LEFT,
        RIGHT,
        UP
    };

    enum eMARGIN_SIZE{
        MARGIN_MIN_SIZE=1,
        MARGIN_MAX_SIZE=10
    };

    bool event(QEvent *event) override;

    void showEvent(QShowEvent* e) override;
    void hideEvent(QHideEvent* e)override;

    void mousePressEvent(QMouseEvent *event)override;
    void mouseMoveEvent(QMouseEvent *event)override;
    void mouseReleaseEvent(QMouseEvent *event)override;
    void leaveEvent(QEvent *event)override;

    void updateRegion(QMouseEvent *event);

    void resizeRegion(int marginTop, int marginBottom,
                      int marginLeft, int marginRight);

private:
    Ui::Widget *ui;
    QTimer timer;
    bool m_bIsPressed = false;
    bool m_bIsResizing = false;
    bool m_bIsDoublePressed = false;

    QPoint m_pressPoint;

    QPoint m_movePoint;

    int m_direction=NONE;

};
#endif // WIDGET_H
