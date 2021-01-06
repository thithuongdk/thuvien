#ifndef project_businessobject_Book_h_
#define project_businessobject_Book_h_

#include <string>
#include "Unit.h"
using namespace std;

class Book : public Unit{
private:
    string _name;
    long _price;
public:
    Book();
    Book(string name, long price);
    virtual Unit* ClonePtr();
    virtual void fromVt();
    virtual void toVt();
    string getName();
    void setName(string name);
    long getPrice();
    void setPrice(long price);
    string toString();
};

#endif //project_businessobject_Book_h_