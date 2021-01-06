
#include "BorrowReturn.h"
using namespace std;


BorrowReturn::BorrowReturn() : Unit(){
    _id = 0;
    _keys.push_back("ID");
    _keys.push_back("MEMBER_ID");
    _keys.push_back("BOOK_ID");
    _keys.push_back("DATE");
    _keys.push_back("BRROW/RETURN");
}
BorrowReturn::BorrowReturn(long memberId, long bookId, string date, int br) : BorrowReturn(){
    _memberId = memberId;
    _bookId = bookId;
    _date = date;
    _br = br;
}

Unit* BorrowReturn::ClonePtr(){
    BorrowReturn* unit = new BorrowReturn();
    return (Unit*)unit;
}
void BorrowReturn::fromVt(vector<string> vts){
    _id = stol(vts[0]);
    _memberId = stol(vts[0]);
    _bookId = stol(vts[0]);
    _date = vts[1];
    _br = stoi(vts[0]);
}
vector<string> BorrowReturn::toVt(){
    vector<string> vts;
    vts.push_back(to_string(_id));
    vts.push_back(to_string(_memberId));
    vts.push_back(to_string(_bookId));
    vts.push_back(_date);
    vts.push_back(to_string(_br));
    return vts;
}

long BorrowReturn::getMemberId(){
    return _memberId;
}
void BorrowReturn::setMemberId(long memberId){
    _memberId = memberId;
}
long BorrowReturn::getBookId(){
    return _bookId;
}
void BorrowReturn::setBookId(long bookId){
    _bookId = bookId;
}
string BorrowReturn::getDate(){
    return _date;
}
void BorrowReturn::setDate(string date){
    _date = date;
}
int BorrowReturn::getBR(){
    return _br;
}
void BorrowReturn::setBR(int br){
    _br = br;
}