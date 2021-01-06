#include "IOData.h"

IOData::IOData(){}

void IOData::dOut(Unit *unit){
    unit->toVt();
    vector<string> keys = unit->getKeys();
    vector<string> values = unit->toVt();
    for(int i = 0; i < keys.size(); i++ ){
        // cout << "value of " << keys.at(i) << " = " << values.at(i) << endl;
        cout << keys.at(i) << " = " << values.at(i) << " ;   ";
    }
    cout << endl;
    // cout << "----------------------------------"<<endl;
}

void IOData::dIn(Unit *unit){
    vector<string> keys = unit->getKeys();
    unit->toVt();
    vector<string> values = unit->toVt();
    bool checkErr;
    for(int i = 1; i < keys.size(); i++ ){
        do{
            checkErr = false;
            cout << "enter value of " << keys.at(i) << " = ";
            getline(cin, values[i]);
            cout << "values[i]"  << values[i];
            try{
            unit->fromVt(values);
            cout << "check  === "; dOut(unit);            
            } catch(...) {
                cout << "wrong type, re enter " << endl;
                checkErr = true;
            }
        }while(checkErr);
    }
    cout << "----------------------------------"<<endl;
}
