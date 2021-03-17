#ifndef EDITSTUDENT_H
#define EDITSTUDENT_H
#include "student.h"
#include <QDialog>

namespace Ui {
class EditStudent;
}

class EditStudent : public QDialog
{
    Q_OBJECT

public:
    explicit EditStudent(QWidget *parent = nullptr,Student *stu = nullptr);
    ~EditStudent();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::EditStudent *ui;
    Student *student;
};

#endif // EDITSTUDENT_H
