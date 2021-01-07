
#include "BaseData.h"
#include "..\businessobject\Member.h"
#include "..\businessobject\Book.h"
#include "..\businessobject\BorrowReturn.h"
#include "..\businessobject\Unit.h"

BaseData::BaseData(){
    _maxId = 0;
    _idUnit.erase(_idUnit.begin(),_idUnit.end());
}
BaseData::BaseData(Unit *unit) : BaseData(){
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

long BaseData::get(long index){
    if(index <1 || index > _maxId){
        return -1;
    }
    for(long i = 0; i < _data.size(); i++){
        if(_data[i]->getId() == index){
            return i;
        }
    }
    return -1;
}

Unit* BaseData::getPtr(long index){
    return _idUnit[index];
}

int BaseData::add(Unit* unit){
    unit->setId(++_maxId);
    _data.push_back(unit);
    _idUnit[_maxId] = unit;
    return 1;
}
int BaseData::add(){
    Unit *unit = cloneUnit();
    IOData::dIn(unit);
    add(unit);
    return 1;
}

int BaseData::edit(long index){
    long i = get(index);
    cout << "get(index) = " << i << endl;
    if(i < 0){ return 0;};
    IOData::dIn(_data[i]);
    return 1;
}

int BaseData::edit(long index, Unit* unit){
    long i = get(index);
    if(i < 0){ return 0;};
    long idOld = _data[i]->getId();
    delete (_data[i]);
    unit->setId(idOld);
    _data[i] = unit;
    return 1;
}
int BaseData::del(long index){
    long i = get(index);
    if(i < 0){ return 0;};
    delete _data[i];
    _data.erase(_data.begin() + i);
    _idUnit.erase (_idUnit.find(i));
    return 1;
}
int BaseData::read(long index){
    long i = get(index);
    if(i < 0){ return 0;};
    IOData::dOut(_data.at(i));
    return 1;
}
int BaseData::read(){
    for(Unit * unit : _data){
        IOData::dOut(unit);
    }
    return 1;
}
int BaseData::toFile(string path){    
    string encode("");
    for(Unit *unit : _data){
        vector<string> vts = unit->toVt();
        for(string s : vts){
            for(int i = 0; i < s.length(); ++i){
                if(s[i] == ' '){
                    s[i] = ';';
                }
            }
            encode +=s + " ";
        }
        encode += "\n";
    }
    encode.resize(encode.size() - 1);
    ofstream outFile(path, ofstream::trunc);
    outFile << encode;
    outFile.close();
    return 1;
};

int BaseData::fromFile(string path){
    ifstream inFile(path);
    const int maxSize = 255;
    char buf[maxSize];
    if(!inFile) {return 0;}
    _maxId = 0;
    while(inFile.getline(buf,maxSize)){
        int len = ((string)buf).size();
        vector<string> vts;
        string s("");
        for(int i = 0; i < len; ++i){
            if(buf[i] == ';'){
                s += " ";
            }else if(buf[i] == ' '){
                string sunit(s);
                vts.push_back(sunit);
                s = "";
            }else{
                s += buf[i];
            }
        }
        Unit *unit = cloneUnit();
        unit->fromVt(vts);
        _data.push_back(unit);
        if(unit->getId() > _maxId) {_maxId = unit->getId();}
    }
    inFile.close();
    return 1;
};
// int BaseData::toMapID(string path){
//     for()
// }