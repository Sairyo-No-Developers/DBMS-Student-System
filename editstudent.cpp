#include "editstudent.h"
#include "ui_editstudent.h"

#include "studentmodel.h"

#include <QMessageBox>

EditStudent::EditStudent(QWidget *parent, Student *s) :
    QDialog(parent),
    ui(new Ui::EditStudent)
{
    QStringList departments = {"CSE","ETCE","EE"};
    ui->setupUi(this);
    this->student = s;
    ui->depts->addItems(departments);
    ui->name->setText(QString::fromStdString(s->getName()));
    ui->phone->setText(QString::fromStdString(s->getPhone()));
    ui->depts->setCurrentIndex(s->getDeptCode());
    ui->address->setText(QString::fromStdString(s->getAddress()));
}

EditStudent::~EditStudent()
{
    delete ui;
}

void EditStudent::on_buttonBox_rejected()
{
    this->done(1);
}

void EditStudent::on_buttonBox_accepted()
{
    StudentModel::instance()->getAndEditStudent( \
                student->getRoll(),
                ui->name->text().toStdString(),
                ui->phone->text().toStdString(),
                ui->address->toPlainText().toStdString(),
                ui->depts->currentIndex()
    );
    this->done(0);
    QMessageBox msgBox;

    msgBox.setWindowTitle("Edit Successful");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText("Student was edited successfully.");
    msgBox.exec();
}
