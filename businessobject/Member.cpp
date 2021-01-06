
#include "Member.h"
using namespace std;


Member::Member() : Unit(){
    _id = 0;
    _keys.push_back("ID");
    _keys.push_back("NAME");
}
Member::Member(string name) : Member(){
    _name = name;
}

Unit* Member::ClonePtr(){
    Member* unit = new Member();
    return (Unit*)unit;
}
void Member::fromVt(vector<string> vts){
    _id = stol(vts[0]);
    _name = vts[1];
}
vector<string> Member::toVt(){
    vector<string> vts;
    vts.push_back(to_string(_id));
    vts.push_back(_name);
    return vts;
}

string Member::getName(){
    return _name;
}
void Member::setName(string name){
    _name = name;
}
// string Member::toString(){
//     return "0";
// }
