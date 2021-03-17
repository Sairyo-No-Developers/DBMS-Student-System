#include "addstudent.h"
#include "ui_addstudent.h"
#include "studentmodel.h"

#include <QMessageBox>

AddStudent::AddStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStudent)
{
    QStringList departments = {"CSE", "ETCE", "EE"};
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
    int deptCode = ui->depts->currentIndex();

    if(name.length() > 0 && roll.length() > 0 && address.length() > 0 && phone.length() > 0) {
        bool result = StudentModel::instance()->getAndAddStudent( \
                    name, \
                    roll, \
                    address, \
                    phone, \
                    deptCode
                    );

        qDebug() << result;
        if (!result) {
            QMessageBox msgBox;
            msgBox.setText("Roll number already exists.");
            msgBox.exec();
        }
        StudentModel::instance()->printAll();
    }
}

void AddStudent::on_buttonBox_rejected()
{
    this->done(1);
}
