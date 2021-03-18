#include "studentlist.h"
#include <QDebug>

vector<Student>::iterator StudentList::searchGetIndex(string roll) {
    auto result = find_if(this->list.begin(), this->list.end(), [&](const Student &s) { return s.getRoll() == roll; });
    return (result == this->list.end()) ? this->list.end() : result;
}

bool StudentList::addStudent(Student & s) {
    auto result = search(s.getRoll());
    if(result != nullopt) {
        qDebug().noquote() << result->toString();
        return false;
    }
    this->list.push_back(s);
    return true;
}

bool StudentList::deleteStudent(string roll) {
    auto result = searchGetIndex(roll);
    if(result == this->list.end()) {
        return false;
    }
    qDebug().noquote() << result->toString();
    this->list.erase(result);
    return true;
}

vector<Student> StudentList::getList() {
    return this->list;
}

void StudentList::editStudent(Student &s, string name, string address, int deptCode, string phone) {
    s.setName(name);
    s.setAddress(address);
    s.setDeptCode(deptCode);
    s.setPhone(phone);
}

QString StudentList::toString() {
    QString s = "[\n";
    for(auto it = this->list.begin(); it != this->list.end(); it++) {
        s += it->toString();
    }
    s += "\n]";
    return s;
}

