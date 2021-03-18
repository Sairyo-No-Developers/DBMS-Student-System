#ifndef DISPLAYALL_H
#define DISPLAYALL_H

#include <QDialog>
#include "student.h"

namespace Ui {
class DisplayAll;
}

class DisplayAll : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayAll(QWidget *parent = nullptr);
    ~DisplayAll();

private slots:
    void on_previous_clicked();

    void on_next_clicked();

private:
    Ui::DisplayAll *ui;
    vector<Student>::iterator it;
    vector<Student> cache;
    QString displayText;
};

#endif // DISPLAYALL_H
