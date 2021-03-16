#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "student.h"

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    Student s("CSE001", 1, "Sandip Murmu", "Green Wood Apartments, Inda, Kharagpur", "8250071935");
    qDebug().noquote() << s.toString();
}

MainMenu::~MainMenu()
{
    delete ui;
}

