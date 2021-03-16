#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <QString>

using namespace std;

class Student {
private:
    string roll;
    int deptCode;
    string name;
    string address;
    string phone;

public:
    Student(string roll, int deptCode, string name, string address, string phone);

    void setRoll(string roll);
    string getRoll() const;

    void setDeptCode(int deptCode);
    int getDeptCode();

    void setName(string name);
    const string getName();

    void setAddress(string address);
    const string getAddress();

    void setPhone(string phone);
    const string getPhone();

    friend ostream & operator << (ostream &out, const Student &s);
    QString toString();
};

#endif // STUDENT_H
