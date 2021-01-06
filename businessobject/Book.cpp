
#include "Book.h"
using namespace std;


Book::Book() : Unit(){
    _id = 0;
    _keys.push_back("ID");
    _keys.push_back("NAME");
    _keys.push_back("PRICE");
}
Book::Book(string name, long price) : Unit(){
    Book();
    _name = name;
    _price = price;
}

Unit* Book::ClonePtr(){
    Book* unit = new Book();
    return (Unit*)unit;
}
void Book::fromVt(){
    _id = stol(_values[0]);
    _name = _values[1];
    _price = stol(_values[2]);
}
void Book::toVt(){
    _values.resize(3);
    _values[0] = to_string(_id);
    _values[1] = _name;
    _values[2] = to_string(_price);
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