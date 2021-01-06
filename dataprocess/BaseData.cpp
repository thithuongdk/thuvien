
#include "BaseData.h"
#include "..\businessobject\Member.h"
#include "..\businessobject\Book.h"
#include "..\businessobject\BorrowReturn.h"
#include "..\businessobject\Unit.h"

BaseData::BaseData(){
    _maxId = 0;
}
BaseData::BaseData(Unit *unit){
    _maxId = 0;
    _unit = unit;
}

Unit* BaseData::cloneUnit(){
    Unit *unit = _unit->ClonePtr();
    return unit;
}
vector<Unit*> BaseData::getData(){
    return _data;
}
void BaseData::setData(vector<Unit*> data){
    _data = data;
}
int BaseData::add(Unit* unit){
    unit->setId(++_maxId);
    _data.push_back(unit);
    return 1;
}
int BaseData::add(){
    Unit *unit = cloneUnit();
    IOData::dIn(unit);
    add(unit);
    return 1;
}

int BaseData::change(int index){
    if(index <0 || index >= _data.size()){
        return 0;
    }
    IOData::dIn(_data[index]);
    return 1;
}

int BaseData::change(int index, Unit* unit){
    if(index <0 || index >= _data.size()){
        return 0;
    }
    long idOld = unit->getId();
    delete (_data[index]);
    _data[index] = unit;
    unit->setId(idOld);
    return 1;
}
int BaseData::del(int index){
    if(index <0 || index >= _data.size()){
        return 0;
    }
    delete _data[index];
    _data.erase(_data.begin() + index);
    return 1;
}
Unit* BaseData::get(int index){
    if(index <0 || index >= _data.size()){
        return nullptr;
    }
    Unit *unit = _data.at(index);
    return unit;
}
int BaseData::read(int index){
    if(index <0 || index >= _data.size()){
        return 0;
    }
    IOData::dOut(_data.at(index));
    return 1;
}
int BaseData::read(){
    for(Unit * unit : _data){
        IOData::dOut(unit);
    }
    return 1;
}