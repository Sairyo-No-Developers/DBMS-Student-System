#ifndef DEPARTMENTLIST_H
#define DEPARTMENTLIST_H
#include <iostream>
#include <vector>
#include <optional>
#include "department.h"

using namespace std;

class DepartmentList
{
private:
    vector<Department> list;
public:
    DepartmentList();
    void addDepartment(Department);
    int getCode(string );
    QList<QString>getNames();
};

#endif // DEPARTMENTLIST_H
