#include "studentmodel.h"
#include "student.h"
#include <QDebug>

StudentModel *StudentModel::sm = nullptr;

bool StudentModel::getAndAddStudent(string name, string roll, string address, string phone, int deptCode) {
    Student s(roll, deptCode, name, address, phone);
    return sl.addStudent(s);
}

bool StudentModel::getAndDeleteStudent(string roll)
{
    return sl.deleteStudent(roll);
}

Student StudentModel::getAndSearchStudent(string roll)
{
    return sl.search(roll);
}
StudentModel  *StudentModel::instance() {
    if(sm == nullptr) {
        sm = new StudentModel;
    }
    return sm;
}
bool StudentModel::getAndEditStudent(Student *s, string name, string address, string phone, int deptCode)
{
    return sl.editStudent(s, name,  address,  deptCode,  phone);
}
void StudentModel::printAll() {
    qDebug().noquote() << sl.toString();
}
