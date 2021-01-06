
#include "Book.h"
using namespace std;


Book::Book() : Unit(){
    _id = 0;
    _keys.push_back("ID");
    _keys.push_back("NAME");
    _keys.push_back("PRICE");
}
Book::Book(string name, long price) : Book(){
    _name = name;
    _price = price;
}

Unit* Book::ClonePtr(){
    Book* unit = new Book();
    return (Unit*)unit;
}
void Book::fromVt(vector<string> vts){
    _id = stol(vts[0]);
    _name = vts[1];
    _price = stol(vts[2]);
}
vector<string> Book::toVt(){
    vector<string> vts;
    vts.push_back(to_string(_id));
    vts.push_back(_name);
    vts.push_back(to_string(_price));
    return vts;
}

string Book::getName(){
    return _name;
}
void Book::setName(string name){
    _name = name;
}
long Book::getPrice(){
    return _price;
}
void Book::setPrice(long price){
    _price = price;
}