#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "student.h"
#include "studentlist.h"
#include "addstudent.h"
#include "studentmodel.h"
#include "editstudent.h"
#include "displayall.h"
#include <QInputDialog>
#include <QMessageBox>
#include "QDebug"
MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    /*
     * Student s1("CSE001", 1, "Sandip Murmu", "Green Wood Apartments, Inda, Kharagpur", "9999999999");
     * Student s2("CSE002", 1, "Sandipan Saha", "Behala, Kolkata", "9999999999");
     * qDebug().noquote() << s1.toString() << s2.toString();
     * StudentList sl;
     * sl.addStudent(s1);
     * sl.addStudent(s2);
     * qDebug().noquote() << sl.toString();
     *
     * if(auto res = sl.search("CSE001"))
     *     qDebug().noquote() << res->toString();
    */
}

MainMenu::~MainMenu()
{
    delete ui;
}


void MainMenu::on_addStudent_clicked()
{
    AddStudent addStudent;
    addStudent.setModal(true);
    addStudent.exec();

}

void MainMenu::on_displayAll_clicked()
{
    DisplayAll displayAll;
    displayAll.setModal(true);
    displayAll.exec();
}

void MainMenu::on_search_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Search"),
                                             tr("Enter Roll Number:"), QLineEdit::Normal,
                                             tr(""), &ok);
    if (ok && !text.isEmpty()) {
        auto res = StudentModel::instance()->search(text.toStdString());
        QMessageBox msgBox;
        if (res.getDeptCode()==-1) {
            qDebug() << "Not found";
            msgBox.setWindowTitle("Search Unsuccessful");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("Student Not Found.");
        } else {
            qDebug().noquote() << res.toString();
            msgBox.setWindowTitle("Search Successful");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText(res.toString());
        }
        msgBox.exec();
    }
}

void MainMenu::on_deleteStudent_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Delete"),
                                             tr("Enter Roll Number:"), QLineEdit::Normal,
                                             tr(""), &ok);
    if (ok && !text.isEmpty()) {
        QMessageBox msgBox;
        auto res = StudentModel::instance()->deleteStudent(text.toStdString());
        if (!res) {
            qDebug() << "Not found";
            msgBox.setWindowTitle("Delete Unsuccessful");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("Student Not Found.");
        } else {
            msgBox.setWindowTitle("Delete Successful");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("Student with roll " + text + " was deleted.");
        }
        msgBox.exec();
    }
}

void MainMenu::on_editStudent_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Edit"),
                                             tr("Enter Roll Number:"), QLineEdit::Normal,
                                             tr(""), &ok);
    if (ok && !text.isEmpty()) {
        QMessageBox msgBox;
        auto res = StudentModel::instance()->search(text.toStdString());
        if(res.getDeptCode()==-1) {
            qDebug() << "Not found";
            msgBox.setWindowTitle("Edit Student Error");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("Student Not Found.");
            msgBox.exec();
        } else {
            Student *s = &res;
            EditStudent editStudent(this, s);
            editStudent.setModal(true);
            editStudent.exec();
        }
    }
}
