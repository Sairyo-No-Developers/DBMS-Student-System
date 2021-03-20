#include "displayall.h"
#include "ui_displayall.h"
#include "studentmodel.h"
#include "QDebug"
DisplayAll::DisplayAll(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayAll)
{
    ui->setupUi(this);
    cache = StudentModel::instance()->getStudentList();
    it = cache.begin();
    for ( index = 0; index < 2; index++) {
        if(it == cache.end())
            break;
        displayText += it->toString();
        it++;  
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
    displayText = "";
    while(index>0)
    {
        index--;
        it--;
    }
    for(index = 1; index >= 0; index--)
    {
        it--;
        displayText = it->toString() + displayText;
    }
    ui->displayArea->setText(displayText);
    ui->previous->setEnabled(true);
    ui->next->setEnabled(true);
    if(it == cache.begin()) {
        ui->previous->setEnabled(false);
        it = it + 2;
    }
}

void DisplayAll::on_next_clicked()
{
    if(it->getRoll()==displayText.mid(6,4

                                      ).toStdString()){
            qDebug()<<"here"<<displayText.mid(6,1);
            it  = it + 2;
     }
    displayText = "";
    for (index = 0; index < 2; index++) {
        if(it == cache.end())
            break;
        displayText += it->toString();
        it++;    
    }
    ui->displayArea->setText(displayText);
    ui->previous->setEnabled(true);   
    if (it == cache.end()) {
        ui->next->setEnabled(false);
    }
    else
        ui->next->setEnabled(true);
}
