#include "gothreeform.h"
ThreeForm *GoThreeForm::threeform=nullptr;
GoThreeForm::GoThreeForm()
{

}
void GoThreeForm::init()
{
    threeform=new ThreeForm;
}
