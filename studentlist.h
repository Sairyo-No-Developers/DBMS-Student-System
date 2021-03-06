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
    auto search(string roll) {
        auto result = find_if(this->list.begin(), this->list.end(), [&](const Student &s) { return s.getRoll() == roll; });
        return (result == this->list.end()) ? nullopt : optional<Student>{*result};
    }

    vector<Student>::iterator searchGetIndex(string roll);
    bool deleteStudent(string roll);
    void editStudent(Student & s, string name, string address, int deptCode, string phone);
    vector<Student> getList();
    QString toString();
};

#endif // STUDENTLIST_H
