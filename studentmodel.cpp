#include "studentmodel.h"
#include "student.h"
#include "department.h"
#include <QDebug>

StudentModel *StudentModel::sm = nullptr;

StudentModel::StudentModel(){
    dl.addDepartment(Department("CSE",101));
    dl.addDepartment(Department("ETCE",110));
    dl.addDepartment(Department("EE",111));
    dl.addDepartment(Department("CHE",011));
    Student s1("0111",011,"CHemical","JU","8929382903");
    Student s2("1011",101,"Computer","Prajukti","98920222");
    Student s3("1101",110,"Mosfet","Prayukti","8676879");
    Student s4("1111",111,"Megger","Sakti","9920920");
    sl.addStudent(s1);
    sl.addStudent(s2);
    sl.addStudent(s3);
    sl.addStudent(s4);

}

bool StudentModel::getAndAddStudent(string name, string roll, string address, string phone, int deptCode) {
    Student s(roll, deptCode, name, address, phone);
    return sl.addStudent(s);
}

StudentModel  *StudentModel::instance() {
    if(sm == nullptr) {
        sm = new StudentModel();
    }
    return sm;
}
int StudentModel::getDeptCode(string s){
    return this->dl.getCode(s);
}

QList<QString> StudentModel::getDeptNames(){
    return dl.getNames();
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
