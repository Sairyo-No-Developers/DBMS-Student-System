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
