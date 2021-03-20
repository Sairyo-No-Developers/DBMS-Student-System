#include "departmentlist.h"
#include "QList"
#include "QString"
DepartmentList::DepartmentList()
{

}
void DepartmentList::addDepartment(Department d)
{
    this->list.push_back(d);
}
int DepartmentList::getCode(string name)
{
    auto result = find_if(this->list.begin(), this->list.end(), [&](const Department &d) { return d.getName() == name; });
    return result->getCode();
}
QList<QString> DepartmentList::getNames(){
    QList<QString> deptName = {};
    for(auto it: list)
        deptName.push_back(QString::fromStdString( it.getName()));
}
