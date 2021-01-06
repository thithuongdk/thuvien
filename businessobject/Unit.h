#ifndef project_businessobject_Unit_h_
#define project_businessobject_Unit_h_

#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Unit{
protected:
    long _id;
    vector<string> _keys;
public:
    Unit();
    virtual Unit* ClonePtr() = 0;
    virtual void fromVt(vector<string> vts) = 0;
    virtual vector<string> toVt() = 0;
    long getId();
    void setId(long Id);
    vector<string> getKeys();
};

#endif //project_businessobject_Unit_h_