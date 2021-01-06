#ifndef project_businessobject_Unit_h_
#define project_businessobject_Unit_h_

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Unit{
protected:
    long _id;
    vector<string> _keys;
    vector<string> _values;
public:
    Unit();
    virtual Unit* ClonePtr() = 0;
    virtual void fromVt() = 0;
    virtual void toVt() = 0;
    long getId();
    void setId(long Id);
    vector<string> getKeys();
    vector<string> getValues();
};

#endif //project_businessobject_Unit_h_