#include "threeform.h"
#include "ui_threeform.h"
#include"gooneform.h"
#include"gotwoform.h"
ThreeForm::ThreeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ThreeForm)
{
    ui->setupUi(this);
}

ThreeForm::~ThreeForm()
{
    delete ui;
}

void ThreeForm::on_goOneButton_clicked()
{
    this->hide();
    GoOneForm::oneform->show();
}

void ThreeForm::on_goTwoButton_clicked()
{
    this->hide();
    GoTwoForm::twoform->show();
}
