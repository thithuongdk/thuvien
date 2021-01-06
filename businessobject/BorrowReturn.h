#ifndef project_businessobject_BorrowReturn_h_
#define project_businessobject_BorrowReturn_h_

#include <string>
#include "Unit.h"
using namespace std;

class BorrowReturn : public Unit{
private:
    long _memberId;
    long _bookId;
    string _date;
    int _br;
public:
    BorrowReturn();
    BorrowReturn(long memberId, long bookId, string date, int br);
    virtual Unit* ClonePtr();
    virtual void fromVt();
    virtual void toVt();
    long getMemberId();
    void setMemberId(long memberId);
    long getBookId();
    void setBookId(long bookId);
    string getDate();
    void setDate(string date);
    int getBR();
    void setBR(int br);
    string toString();
};

#endif //project_businessobject_BorrowReturn_h_