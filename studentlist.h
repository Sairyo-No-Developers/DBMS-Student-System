#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <iostream>
#include <vector>
#include <optional>
#include "student.h"

using namespace std;

class StudentDisplayResponse {
public:
    bool hasPrev;
    bool hasNext;
    vector<Student> students;

    StudentDisplayResponse(bool hasPrev, bool hasNext, vector<Student> students) {
        this->hasPrev = hasPrev;
        this->hasNext = hasNext;
        this->students = students;
    }
};

class StudentList
{
private:
    vector<Student> list;
public:
    bool addStudent(Student & s);
    Student search(string roll) {
           auto result = find_if(this->list.begin(), this->list.end(), [&](const Student &s) { return s.getRoll() == roll; });
           return result == this->list.end() ? Student("x",-1,"x","x","x") : *result;
       }

    vector<Student>::iterator searchGetIndex(string roll);
    bool deleteStudent(string roll);
    bool editStudent(Student  *s, string name, string address, int deptCode, string phone);
    vector<Student> displayAll();
    QString toString();
};

#endif // STUDENTLIST_H
