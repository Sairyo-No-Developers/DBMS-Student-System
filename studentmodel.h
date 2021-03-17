#ifndef STUDENTMODEL_H
#define STUDENTMODEL_H

#include "studentlist.h"

class StudentModel
{
protected:
    StudentList sl;
    static StudentModel *sm;
public:
    StudentModel(){};
    StudentModel(StudentModel &other) = delete;
    void operator=(const StudentModel &) = delete;
    bool getAndAddStudent(string name, string roll, string address, string phone, int deptCode);
    bool getAndDeleteStudent(string roll);
    Student getAndSearchStudent(string roll);
    bool getAndEditStudent(Student *s,string name, string address, string phone, int deptCode);
    void printAll();
    static StudentModel *instance();
};

#endif // STUDENTMODEL_H
