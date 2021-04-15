#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);
    //定义函数指针
    void(QSpinBox:: *spin)(int)=&QSpinBox::valueChanged;
    //让spin控制slider
    connect(ui->spinBox,spin,ui->horizontalSlider,&QSlider::setValue);

    //让slider 控制spin
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
}
//设置参数函数
void SmallWidget::setNum(int a)
{
    ui->spinBox->setValue(a);

}
//获取参数
int SmallWidget::getNum()
{
    return ui->spinBox->value();
}
SmallWidget::~SmallWidget()
{
    delete ui;
}
