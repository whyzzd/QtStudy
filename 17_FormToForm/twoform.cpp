#include "twoform.h"
#include "ui_twoform.h"
#include"gooneform.h"
#include"gothreeform.h"
TwoForm::TwoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TwoForm)
{
    ui->setupUi(this);
}

TwoForm::~TwoForm()
{
    delete ui;
}

void TwoForm::on_goOneButton_clicked()
{
    this->hide();
    GoOneForm::oneform->show();

}

void TwoForm::on_goThreeButton_clicked()
{
    this->hide();
    GoThreeForm::threeform->show();
}
