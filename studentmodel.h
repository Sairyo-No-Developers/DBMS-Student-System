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
    auto search(string roll) {
        return sl.search(roll);
    }
    bool deleteStudent(string roll);
    bool getAndEditStudent(string roll, string name, string phone, string address, int deptCode);
    void printAll();
    static StudentModel *instance();
};

#endif // STUDENTMODEL_H
