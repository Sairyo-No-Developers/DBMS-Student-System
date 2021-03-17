#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "student.h"
#include "studentlist.h"
#include "addstudent.h"
#include "studentmodel.h"

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
