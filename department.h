#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <iostream>
#include <QString>
using namespace std;

class Department
{
private:
    string name;
    int code;
public:
    Department(string ,int );
    const string getName() const;
    int getCode();
};

#endif // DEPARTMENT_H
