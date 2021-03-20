#include "department.h"

Department::Department(string name,int dept)
{
    this->name = name;
    this->code = dept;
}
const string Department::getName() const {
    return this->name;
}
int Department::getCode()
{
    return this->code;
}
