#ifndef project_dataprocess_Control_h_
#define project_dataprocess_Control_h_

#include "..\businessobject\Member.h"
#include "..\businessobject\BorrowReturn.h"
#include "..\businessobject\Book.h"
#include "..\businessobject\Unit.h"
#include "..\dataprocess\BaseData.h"
#include "IOData.h"
#include <vector>
#include <iostream>
using namespace std;

class Control{
private:
    BaseData *_memberData;
    BaseData *_bookData;
    BaseData *_brData;
public:
    Control();
    void init();
    void home();
    int q1_CRUD();
    int q2();
    int q3();
    int q4();
};

#endif //project_dataprocess_Control_h_