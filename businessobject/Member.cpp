
#include "Member.h"
using namespace std;


Member::Member() : Unit(){
    _id = 0;
    _keys.push_back("ID");
    _keys.push_back("NAME");
}
Member::Member(string name) : Unit(){
    Member();
    _name = name;
}

Unit* Member::ClonePtr(){
    Member* unit = new Member();
    return (Unit*)unit;
}
void Member::fromVt(){
    _id = stol(_values[0]);
    _name = _values[1];
}
void Member::toVt(){
    _values.resize(2);
    _values[0] = to_string(_id);
    _values[1] = _name;
}

string Member::getName(){
    return _name;
}
void Member::setName(string name){
    _name = name;
}
string Member::toString(){
    return "0";
}
