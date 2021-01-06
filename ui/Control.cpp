
#include "Control.h"

Control::Control(){
    _memberData = new BaseData(new Member());
    _bookData = new BaseData(new Book());
    _brData = new BaseData(new BorrowReturn());
}

void Control::init(){
    _memberData->add(new Member("tran"));
    _memberData->add(new Member("nguyen"));
    _memberData->add(new Member("thi"));
    _memberData->add(new Member("thuong"));
    _bookData->add(new Book("sach1", 1000));
    _bookData->add(new Book("sach2", 2000));
    _bookData->add(new Book("sach3", 3000));
    _bookData->add(new Book("sach4", 4000));
    _brData->add(new BorrowReturn(1, 1,"20200101", 1));
    _brData->add(new BorrowReturn(2, 2,"20200201", 1));
    _brData->add(new BorrowReturn(1, 4,"20200501", 1));
    _brData->add(new BorrowReturn(3, 3,"20200301", 1));
    _brData->add(new BorrowReturn(1, 2,"20200401", 1));
    _brData->add(new BorrowReturn(1, 4,"20200601", -1));
    _brData->add(new BorrowReturn(2, 2,"20200401", -1));
    _memberData->read();
    _bookData->read();
    _brData->read();
}

void Control::home(){
    int select = 0;
    int iExit = 0;
    do{
        select = 0;
        system("pause");
        cout<< "HOME"<<endl;
        cout<< "    1.Add/change/delete/read"<<endl;
        cout<< "    2."<<endl;
        cout<< "    3."<<endl;
        cout<< "    4."<<endl;
        cout<< "please select action: ";
        cin >> select; cin.ignore();
        iExit = 0;
        switch (select){
            case 1:
                iExit = q1_CRUD();
                break;
            case 2:
                iExit = q2();
                break;
            case 3:
                iExit = q3();
                break;
            case 4:
                iExit = q4();
                break;
            
            default:
                select = 0;
        }
    } while (select != 0 && iExit != 0);
    cout<< "Quit"<<endl;
}
int Control::q1_CRUD(){
    
    int select = 0;
    int selectTable = 0;
    int iExit = 0;
    BaseData *bsData;
    do{
        system("pause");
        selectTable = 0;
        cout<< "*CRUD"<<endl;
        cout<< "Select table"<<endl;
        cout<< "    0.Back"<<endl;
        cout<< "    1.Member"<<endl;
        cout<< "    2.Book"<<endl;
        cout<< "    3.Borrow Return"<<endl;
        cout<< "    ~.Exit"<<endl;
        cin >> selectTable; cin.ignore();
        iExit = 0;
        switch (selectTable){
            case 0:
                return 1;
            case 1:
                bsData = _memberData;
                break;
            case 2:
                bsData = _bookData;
                break;
            case 3:
                bsData = _brData;
                break;
            default:
                return 0;
        }

        select = 0;
        cout<< "Select CRUD"<<endl;
        cout<< "    0.Back"<<endl;
        cout<< "    1.Add"<<endl;
        cout<< "    2.Read by ID"<<endl;
        cout<< "    3.Read all"<<endl;
        cout<< "    4.Change by ID"<<endl;
        cout<< "    5.Delete by ID"<<endl;
        cout<< "    ~.Exit"<<endl;
        cout<< "please select action: ";
        cin >> select; cin.ignore();
        iExit = 0;
        int index = 0;
        switch (select){
            case 0:
                return 1;
            case 1:
                bsData->add();
                break;
            case 2:
                cout<< "please select index: ";
                cin >> index; cin.ignore();
                bsData->read(index);
                break;
            case 3:
                bsData->read();
                break;
            case 4:
                cout<< "please select index: ";
                cin >> index; cin.ignore();
                bsData->read(index);
                cout<< "please change " << endl;
                bsData->change(index);
                break;
            case 5:
                cout<< "please select index: ";
                cin >> index; cin.ignore();
                bsData->read(index);
                cout<< "confrim delete y/n " << endl;
                char cf;
                cin >> cf; cin.ignore();
                if(cf == 'y'){
                    bsData->del(index);
                    cout<< "done del" << endl;
                }
                break;        
            default:
                return 0;
        }
    } while (select != 0 && iExit != 0);
    return 1;
};
int Control::q2(){return 1;};
int Control::q3(){return 1;};
int Control::q4(){return 1;};