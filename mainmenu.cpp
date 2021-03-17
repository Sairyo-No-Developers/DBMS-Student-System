#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "student.h"
#include "studentlist.h"
#include "addstudent.h"
#include "studentmodel.h"
#include "QLineEdit"
#include "QInputDialog"
#include "QDebug"
#include "QMessageBox"
#include "editstudent.h"

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
    StudentModel::instance()->printAll();
}

void MainMenu::on_deleteStudent_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Search"),
                                                 tr("Enter Roll Number:"), QLineEdit::Normal,
                                                 tr(""), &ok);
    if("ok" && !text.isEmpty())
    {
        bool result = StudentModel::instance()->getAndDeleteStudent(text.toStdString());
        if (result) {
            QMessageBox msgBox;
            msgBox.setText("Roll " + text + " deleted successfully");
            msgBox.exec();
        }
        else{
            QMessageBox msgBox;
            msgBox.setText("Roll doesnot exists");
            msgBox.exec();
        }
    }
}

void MainMenu::on_search_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Search"),
                                                 tr("Enter Roll Number:"), QLineEdit::Normal,
                                                 tr(""), &ok);
    if("ok" && !text.isEmpty())
    {
        Student result = StudentModel::instance()->getAndSearchStudent(text.toStdString());
        if(result.getDeptCode()==-1)
        {
            QMessageBox msgBox;
            msgBox.setText("Roll doesnot exists");
            msgBox.exec();
        }
        else
            qDebug().noquote()<<result.toString();
    }
}

void MainMenu::on_editStudent_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Search"),
                                                 tr("Enter Roll Number:"), QLineEdit::Normal,
                                                 tr(""), &ok);
    if("ok" && !text.isEmpty())
    {
        Student result = StudentModel::instance()->getAndSearchStudent(text.toStdString());
        if(result.getDeptCode()==-1)
        {
            QMessageBox msgBox;
            msgBox.setText("Roll doesnot exists");
            msgBox.exec();
        }
        else
        {
            EditStudent etd_stud(this,&result);
            etd_stud.setModal(true);
            etd_stud.exec();
            qDebug().noquote()<<result.toString();
        }
    }
}
