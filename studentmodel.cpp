#include "studentmodel.h"
#include "student.h"
#include <QDebug>

StudentModel *StudentModel::sm = nullptr;

bool StudentModel::getAndAddStudent(string name, string roll, string address, string phone, int deptCode) {
    Student s(roll, deptCode, name, address, phone);
    return sl.addStudent(s);
}

StudentModel  *StudentModel::instance() {
    if(sm == nullptr) {
        sm = new StudentModel;
    }
    return sm;
}

void StudentModel::printAll() {
    qDebug().noquote() << sl.toString();
}

bool StudentModel::deleteStudent(string roll) {
    return sl.deleteStudent(roll);
}

bool StudentModel::getAndEditStudent(string roll, string name, string phone, string address, int deptCode) {
    auto it = sl.searchGetIndex(roll);
    it->setName(name);
    it->setPhone(phone);
    it->setDeptCode(deptCode);
    it->setAddress(address);
    return true;
}

vector<Student> StudentModel::getStudentList() {
    return sl.getList();
}
