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
#include <algorithm>    // std::sort
#include <map>
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
    int q2_BackupRestore();
    int q3_MostBorrow();
    int q4_MostDebt();
};

#endif //project_dataprocess_Control_h_