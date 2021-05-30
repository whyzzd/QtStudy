#include "gooneform.h"
OneForm *GoOneForm::oneform=nullptr;//定义的时候不使用static关键字
GoOneForm::GoOneForm()
{

}
void GoOneForm::init()
{
    oneform =new OneForm;

}
