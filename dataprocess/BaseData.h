#ifndef project_dataprocess_BaseData_h_
#define project_dataprocess_BaseData_h_

#include "..\businessobject\Unit.h"
#include "..\ui\IOData.h"
#include <vector>
using namespace std;

class BaseData{
private:
    vector<Unit*> _data;
    Unit* _unit;
    long _maxId;
public:
    BaseData();
    BaseData(Unit *unit);
    Unit* cloneUnit(); 
    vector<Unit*> getData();    
    void setData(vector<Unit*> data);
    int add(Unit* unit);
    int add();
    int change(int index);
    int change(int index, Unit* unit);
    int del(int index);
    Unit* get(int index);
    int read(int index);
    int read();
};

#endif //project_dataprocess_BaseData_h_