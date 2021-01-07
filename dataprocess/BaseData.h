#ifndef project_dataprocess_BaseData_h_
#define project_dataprocess_BaseData_h_

#include "..\businessobject\Unit.h"
#include "..\ui\IOData.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class BaseData{
private:
    map<int, Unit*> _idUnit;
    vector<Unit*> _data;
    Unit* _unit;
    long _maxId;
public:
    BaseData();
    BaseData(Unit *unit);
    Unit* cloneUnit();
    int toMapID();
    int toFile(string path);
    int fromFile(string path);  
    vector<Unit*> getData();
    void setData(vector<Unit*> data);  
    int add(Unit* unit);
    int add();
    int edit(long index);
    int edit(long index, Unit* unit);
    int del(long index);
    Unit* getPtr(long index);
    long get(long index);
    int read(long index);
    int read();
};

#endif //project_dataprocess_BaseData_h_