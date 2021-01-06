#ifndef project_ui_IOData_h_
#define project_ui_IOData_h_

#include <string>
#include <iostream>
#include "..\businessobject\Unit.h"
#include "..\dataprocess\BaseData.h"
using namespace std;

class IOData{
private:
    string i;
public:
    IOData();
    static void dOut(Unit*);
    static void dIn(Unit*);
};

#endif //project_ui_IOData_h_