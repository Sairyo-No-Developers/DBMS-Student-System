#include "addstudent.h"
#include "ui_addstudent.h"
#include "studentmodel.h"
#include "departmentlist.h"
#include "QDebug"
#include <QMessageBox>

AddStudent::AddStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStudent)
{
    QStringList departments = StudentModel::instance()->getDeptNames();
    ui->setupUi(this);
    ui->depts->addItems(departments);
}

AddStudent::~AddStudent()
{
    delete ui;
}

void AddStudent::on_buttonBox_accepted()
{
    string name = ui->name->text().toStdString();
    string roll = ui->roll->text().toStdString();
    string address = ui->address->toPlainText().toStdString();
    string phone = ui->phone->text().toStdString();
    string deptName = ui->depts->currentText().toStdString();

    int code = StudentModel::instance()->getDeptCode(deptName);
    roll = to_string(code) + roll;

    if(name.length() > 0 && roll.length() > 0 && address.length() > 0 && phone.length() > 0) {
        bool result = StudentModel::instance()->getAndAddStudent( \
                    name, \
                    roll, \
                    address, \
                    phone, \
                    code
                    );

        qDebug() << result;
        if (!result) {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Add Student Error");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("Roll number already exists.");
            msgBox.exec();
        }
        else{
            QMessageBox msgBox;
            msgBox.setWindowTitle("Success");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("Your Roll number is "+QString::fromStdString( roll));
            msgBox.exec();
        }
        StudentModel::instance()->printAll();
    }
    ui->name->clear();
    ui->roll->clear();
    ui->phone->clear();
    ui->address->clear();
    ui->depts->clearFocus();
}

void AddStudent::on_buttonBox_rejected()
{
    this->done(1);
}
