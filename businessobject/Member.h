#ifndef project_businessobject_Member_h_
#define project_businessobject_Member_h_

#include <string>
#include "Unit.h"
using namespace std;

class Member : public Unit{
private:
    string _name;
public:
    Member();
    Member(string name);
    virtual Unit* ClonePtr();
    virtual void fromVt(vector<string> vts);
    virtual vector<string> toVt();
    string getName();
    void setName(string name);
    // string toString();
};

#endif //project_businessobject_Member_h_