#include "oneform.h"
#include "ui_oneform.h"
#include"gotwoform.h"
#include"gothreeform.h"
OneForm::OneForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OneForm)
{
    ui->setupUi(this);
}

OneForm::~OneForm()
{
    delete ui;
}


void OneForm::on_goTwoButton_clicked()
{
    this->hide();
    GoTwoForm::twoform->show();

}

void OneForm::on_goThreeButton_clicked()
{
    this->hide();
    GoThreeForm::threeform->show();

}
