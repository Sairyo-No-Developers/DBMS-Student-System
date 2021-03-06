#ifndef STUDENTMODEL_H
#define STUDENTMODEL_H

#include "studentlist.h"
#include "departmentlist.h"

class StudentModel
{
protected:
    StudentList sl;
    DepartmentList dl;
    static StudentModel *sm;
public:
    StudentModel();
    StudentModel(StudentModel &other) = delete;
    void operator=(const StudentModel &) = delete;
    bool getAndAddStudent(string name, string roll, string address, string phone, int deptCode);
    auto search(string roll) {
        return sl.search(roll);
    }
    int getDeptCode(string);
    bool deleteStudent(string roll);
    bool getAndEditStudent(string roll, string name, string phone, string address, int deptCode);
    void printAll();
    vector<Student> getStudentList();
    static StudentModel *instance();
    QList<QString> getDeptNames();
};

#endif // STUDENTMODEL_H
