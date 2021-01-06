
#include "Member.h"
using namespace std;

Unit::Unit(){
    _id = 0;
    _keys.resize(0);
    _values.resize(0);
}
long Unit::getId(){
    return _id;
}
void Unit::setId(long Id){
    _id = Id;
}
vector<string> Unit::getKeys(){
    return _keys;
}
vector<string> Unit::getValues(){
    return _values;
}