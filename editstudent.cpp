#include "editstudent.h"
#include "ui_editstudent.h"
#include "studentmodel.h"
#include "QDebug"
#include "QMessageBox"
EditStudent::EditStudent(QWidget *parent,Student *stu) :
    QDialog(parent),
    ui(new Ui::EditStudent)
{
    QStringList departments = {"CSE", "ETCE", "EE"};
    ui->setupUi(this);
    ui->depts->addItems(departments);
    student = stu;
    ui->name->setText(QString::fromStdString(student->getName()));
    ui->phone->setText(QString::fromStdString(student->getPhone()));
    ui->address->setText(QString::fromStdString(student->getAddress()));
    ui->depts->setCurrentIndex(student->getDeptCode());
}

EditStudent::~EditStudent()
{
    delete ui;
}

void EditStudent::on_buttonBox_accepted()
{
    string name = ui->name->text().toStdString();
    string address = ui->address->toPlainText().toStdString();
    string phone = ui->phone->text().toStdString();
    int deptCode = ui->depts->currentIndex();
    if(name.length() > 0 && address.length() > 0 && phone.length() > 0) {
        bool result = StudentModel::instance()->getAndEditStudent( \
                    student, \
                    name, \
                    address, \
                    phone, \
                    deptCode
                    );

        qDebug() << result;
        if (result) {
            QMessageBox msgBox;
            msgBox.setText("Successfully updated");
            msgBox.exec();
        }
        //StudentModel::instance()->printAll();
        ui->name->clear();
        ui->phone->clear();
        ui->address->clear();
        ui->depts->clearFocus();
    }
}

void EditStudent::on_buttonBox_rejected()
{
    this->done(1);
}
