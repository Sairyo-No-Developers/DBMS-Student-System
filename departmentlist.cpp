#include "departmentlist.h"

void DepartmentList::addDepartment(Department d) {
    this->list.push_back(d);
}

QList<QString> DepartmentList::getNames() {
    QList<QString> deptNames = {};
    for(auto &it: list) {
        deptNames.push_back(QString::fromStdString(it.getName()));
    }
    return deptNames;
}
