#include <iostream>
#include "businessobject\Member.h"
#include "businessobject\Unit.h"
#include "dataprocess\BaseData.h"
#include "ui\Control.h"
#include "ui\IOData.h"

using namespace std;

int main(){
    cout << "=================begin=================" <<endl;
    cout << "=================input=================" <<endl;
    Control ctrl;
    ctrl.init();
    ctrl.home();
    return 1;


}
