#include "student.h"


Student::Student(string roll, int deptCode, string name, string address, string phone) {
    this->roll = roll;
    this->deptCode = deptCode;
    this->name = name;
    this->address = address;
    this->phone = phone;
}

void Student::setRoll(string roll) {
    this->roll = roll;
}

void Student::setName(string name) {
    this->name = name;
}

void Student::setDeptCode(int deptCode) {
    this->deptCode = deptCode;
}

void Student::setAddress(string address) {
    this->address = address;
}

void Student::setPhone(string phone) {
    this->phone = phone;
}


const string Student::getRoll() const {
    return this->roll;
}

int Student::getDeptCode() {
    return this->deptCode;
}

const string Student::getPhone() {
    return this->phone;
}

const string Student::getName() {
    return this->name;
}

const string Student::getAddress() {
    return this->address;
}

ostream & operator << (ostream &out, const Student &s) {
    out << "{"
        << "\nname: " << s.name
        << "\nroll: " << s.roll
        << "\ndeptCode: " << s.deptCode
        << "\naddress: " << s.address
        << "\nphone: " << s.phone
        << "\n}";

    return out;
}

QString Student::toString() {
    return QString::fromStdString( \
                "{\n\tname: " + this->name
               + "\n\troll: " + this->roll
               + "\n\tdeptCode: " + to_string(this->deptCode)
               + "\n\taddress: " + this->address
               + "\n\tphone: " + this->phone
               + "\n}" );
}
