
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
BorrowReturn::BorrowReturn(long memberId, long bookId, string date, int br) : Unit(){
    BorrowReturn();
    _memberId = memberId;
    _bookId = bookId;
    _date = date;
    _br = br;
}

Unit* BorrowReturn::ClonePtr(){
    BorrowReturn* unit = new BorrowReturn();
    return (Unit*)unit;
}
void BorrowReturn::fromVt(){
    _id = stol(_values[0]);
    _memberId = stol(_values[0]);
    _bookId = stol(_values[0]);
    _date = _values[1];
    _br = stoi(_values[0]);
}
void BorrowReturn::toVt(){
    _values.resize(5);
    _values[0] = to_string(_id);
    _values[1] = to_string(_memberId);
    _values[2] = to_string(_bookId);
    _values[3] = _date;
    _values[4] = to_string(_br);
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