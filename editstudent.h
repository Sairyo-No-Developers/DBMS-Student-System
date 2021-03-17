#ifndef EDITSTUDENT_H
#define EDITSTUDENT_H

#include <QDialog>
#include "student.h"

namespace Ui {
class EditStudent;
}

class EditStudent : public QDialog
{
    Q_OBJECT

public:
    explicit EditStudent(QWidget *parent = nullptr, Student *s = nullptr);
    ~EditStudent();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::EditStudent *ui;
    Student *student;
};

#endif // EDITSTUDENT_H
