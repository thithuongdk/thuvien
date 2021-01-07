
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
    cout<< "========Member Table==========="<<endl;
    _memberData->read();
    cout<< "========Book Table==========="<<endl;
    _bookData->read();
    cout<< "========BR Table==========="<<endl;
    _brData->read();
}

void Control::home(){
    int select = 0;
    int iExit = 0;
    system("PAUSE");
    do{
        select = 0;
        system("CLS");
        cout<< "HOME"<<endl;
        cout<< "    1.Add/edit/delete/read"<<endl;
        cout<< "    2.Backup and Restore"<<endl;
        cout<< "    3.Most borrow"<<endl;
        cout<< "    4.Most debt"<<endl;
        cout<< "please select action: ";
        cin >> select; cin.ignore();
        system("CLS");
        iExit = 0;
        switch (select){
            case 1:
                iExit = q1_CRUD();
                break;
            case 2:
                iExit = q2_BackupRestore();
                break;
            case 3:
                iExit = q3_MostBorrow();
                break;
            case 4:
                iExit = q4_MostDebt();
                break;
            
            default:
                select = 0;
        }
        system("pause");
    } while (select != 0 && iExit != 0);
    cout<< "Quit"<<endl;
}
int Control::q1_CRUD(){
    
    int select = 0;
    int selectTable = 0;
    int iExit = 0;
    BaseData *bsData;
    do{
        selectTable = 0;
        cout<< "*CRUD"<<endl;
        cout<< "Select table"<<endl;
        cout<< "    0.Back"<<endl;
        cout<< "    1.Table Member"<<endl;
        cout<< "    2.Table Book"<<endl;
        cout<< "    3.Table Borrow Return"<<endl;
        cout<< "    ~.Exit"<<endl;
        cin >> selectTable; cin.ignore();
        system("CLS");
        iExit = 0;
        string sTable = "";
        switch (selectTable){
            case 0:
                return 1;
            case 1:
                sTable = "Member";
                bsData = _memberData;
                break;
            case 2:
                sTable = "Book";
                bsData = _bookData;
                break;
            case 3:
                sTable = "Borrow Return";
                bsData = _brData;
                break;
            default:
                return 0;
        }

        do{
            select = 0;
            cout<< "Table " << sTable << " select CRUD"<<endl;
            cout<< "    0.Back"<<endl;
            cout<< "    1.Add"<<endl;
            cout<< "    2.Read by ID"<<endl;
            cout<< "    3.Read all"<<endl;
            cout<< "    4.edit by ID"<<endl;
            cout<< "    5.Delete by ID"<<endl;
            cout<< "    ~.Exit"<<endl;
            cout<< "please select action: ";
            cin >> select; cin.ignore();
            iExit = 0;
            long index = 0;
            switch (select){
                case 0:
                    return 1;
                    break;
                case 1:
                    // add data
                    bsData->add();
                    bsData->read();
                    iExit = 1;
                    break;
                case 2:
                    // read data by ID
                    cout<< "please select read ID: ";
                    cin >> index; cin.ignore();
                    if(bsData->read(index) == 0) { cout<< "not found ID " << endl; break;}
                    iExit = 1;
                    break;
                case 3:
                    // read all data
                    bsData->read();
                    iExit = 1;
                    break;
                case 4:
                    // edit data by id
                    bsData->read();
                    cout<< "please select edit ID: ";
                    cin >> index; cin.ignore();
                    if(bsData->read(index) == 0) { cout<< "not found ID " << endl; break;}
                    cout<< "please edit " << endl;
                    bsData->edit(index);
                    bsData->read();
                    iExit = 1;
                    break;
                case 5:
                    // delete by id
                    bsData->read();
                    cout<< "please select delete ID: ";
                    cin >> index; cin.ignore();
                    if(bsData->read(index) == 0) { cout<< "not found ID " << endl; break;}
                    cout<< "confrim delete y/n " << endl;
                    char cf;
                    cin >> cf; cin.ignore();
                    if(cf == 'y'){
                        bsData->del(index);
                        cout<< "done del" << endl;
                    }
                    bsData->read();
                    iExit = 1;
                    break;        
                default:
                    return 0;
            }
            system("PAUSE");
            system("CLS");
        } while (select != 0 && iExit != 0);
    } while (selectTable != 0 && iExit != 0);
    return 1;
};
int Control::q2_BackupRestore(){
    
    int select = 0;
    int selectTable = 0;
    int iExit = 0;
    BaseData *bsData = nullptr;
    do{
        selectTable = 0;
        bsData = nullptr;
        cout<< "*CRUD"<<endl;
        cout<< "Select table"<<endl;
        cout<< "    0.Back"<<endl;
        cout<< "    1.Table Member"<<endl;
        cout<< "    2.Table Book"<<endl;
        cout<< "    3.Table Borrow Return"<<endl;
        cout<< "    ~.Exit"<<endl;
        cin >> selectTable; cin.ignore();
        system("CLS");
        iExit = 0;
        string sTable = "";
        switch (selectTable){
            case 0:
                return 1;
            case 1:
                sTable = "Member";
                bsData = _memberData;
                break;
            case 2:
                sTable = "Book";
                bsData = _bookData;
                break;
            case 3:
                sTable = "Borrow Return";
                bsData = _brData;
                break;
            default:
                return 0;
        }
        string path = "data\\" + to_string(selectTable) + ".data";

        do{
            select = 0;
            cout<< "Table " << sTable << " select CRUD"<<endl;
            cout<< "    0.Back"<<endl;
            cout<< "    1.Backup"<<endl;
            cout<< "    2.Restore"<<endl;
            cout<< "    ~.Exit"<<endl;
            cout<< "please select action: ";
            cin >> select; cin.ignore();
            iExit = 0;
            long index = 0;
            switch (select){
                case 0:
                    return 1;
                    break;
                case 1:
                    cout<< "Backup... ";
                    bsData->toFile(path);
                    cout<< "backup done!" << endl;
                    iExit = 1;
                    break;
                case 2:
                    // read data by ID
                    cout<< "Restore... ";
                    if(bsData->fromFile(path) == 0) { cout<< "not found file backup " << endl; break;}
                    cout<< "restore done!" << endl;
                    iExit = 1;
                    break;
                default:
                    return 0;
            }
            system("PAUSE");
            system("CLS");
        } while (select != 0 && iExit != 0);
    } while (selectTable != 0 && iExit != 0);
    return 1;
};
int Control::q3_MostBorrow(){
    cout<< "*N books are borrowed the most"<<endl;
    cout<< " please enter N = ";
    int n;
    cin >> n; cin.ignore();
    vector<Unit*> books = _bookData->getData();
    vector<Unit*> brs = _brData->getData();

    map<long , int> mapBookBorrow;
    for(Unit *unit : brs){
        BorrowReturn *br = (BorrowReturn *) unit;
        if(br->getBR() == 1) {
            mapBookBorrow[br->getBookId()]++;
        }
    }
    sort(books.begin(),books.end(),[&mapBookBorrow](Unit *a,Unit *b){return mapBookBorrow[a->getId()] > mapBookBorrow[b->getId()];});
    _bookData->read();
    cout<< " list " << n <<" books are borrowed the most : " <<endl;
    for(int i = 0; i< books.size() && i < n; ++i){
        IOData::dOut(books[i]);
        cout<< "                    borrowed is " << mapBookBorrow[books[i]->getId()]<< endl;
    }
    return 1;
};
int Control::q4_MostDebt(){
    
    cout<< "*N member are debt the most"<<endl;
    cout<< " please enter N = ";
    int n;
    cin >> n; cin.ignore();
    vector<Unit*> members = _memberData->getData();
    vector<Unit*> brs = _brData->getData();

    map<long , long> mapMemberBorrow;
    for(Unit *unit : brs){
        BorrowReturn *br = (BorrowReturn *) unit;
        if(br->getBR() == 1) {
            Book *book = (Book *)_bookData->getPtr(br->getBookId());
            long debt = br->getBR() * book->getPrice();
            mapMemberBorrow[br->getMemberId()] += debt;
        }
    }
    sort(members.begin(),members.end(),[&mapMemberBorrow](Unit *a,Unit *b){return mapMemberBorrow[a->getId()] > mapMemberBorrow[b->getId()];});
    _brData->read();
    cout<< " list " << n <<" member are debt  the most : " <<endl;
    for(int i = 0; i< members.size() && i < n; ++i){
        IOData::dOut(members[i]);
        cout<< "                    debt is " << mapMemberBorrow[members[i]->getId()]<< endl;
    }
    return 1;
};