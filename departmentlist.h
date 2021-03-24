#ifndef DEPARTMENTLIST_H
#define DEPARTMENTLIST_H

#include "department.h"
#include <vector>
#include <iostream>
#include<QList>
#include<QString>
#include<optional>
#include<QDebug>

using namespace std;

class DepartmentList
{
private:
    vector<Department> list;
public:
    DepartmentList(){};
    void addDepartment(Department);
    auto getCode(string name) {
        qDebug() << QString::fromStdString(name);
        auto result = find_if(this->list.begin(), this->list.end(), [&](const Department &d) {return d.getName() == name; });
        qDebug() << "RESULT" << QString::fromStdString(result->getName());
        return (result == this->list.end()) ? nullopt : optional<int>(result->getCode());
    }
    QList<QString> getNames();
};

#endif // DEPARTMENTLIST_H
