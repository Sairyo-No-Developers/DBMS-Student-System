#include "department.h"

Department::Department(string name, int code)
{
    this->name = name;
    this->code = code;
}

const string Department::getName() const {
    return this->name;
}

int Department::getCode() {
    return this->code;
}
