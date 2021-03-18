#include "displayall.h"
#include "ui_displayall.h"
#include "studentmodel.h"

DisplayAll::DisplayAll(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayAll)
{
    ui->setupUi(this);
    cache = StudentModel::instance()->getStudentList();
    it = cache.begin();
    displayText += it->toString();
    for (int i = 0; i < 1; i++) {
        it++;
        displayText += it->toString();
        if(it == cache.end())
            break;
    }
    ui->displayArea->setText(displayText);

    ui->previous->setEnabled(false);

    if(it == cache.end())
        ui->next->setEnabled(false);
}

DisplayAll::~DisplayAll()
{
    delete ui;
}

void DisplayAll::on_previous_clicked()
{
    it--;
    ui->displayArea->setText(it->toString());
    ui->previous->setEnabled(true);
    ui->next->setEnabled(true);
    if(it == cache.begin()) {
        ui->previous->setEnabled(false);
    }
}

void DisplayAll::on_next_clicked()
{
    qDebug() << "Here" << it->toString();
    displayText = "";
    for (int i = 0; i < 2; i++) {
        if(it == cache.end())
            break;
        qDebug() << "Here" << i << it->toString();
        it++;
        displayText += it->toString();
    }
    ui->displayArea->setText(displayText);
    ui->previous->setEnabled(true);
    ui->next->setEnabled(true);
    if (it == cache.end()) {
        ui->next->setEnabled(false);
    }
}
