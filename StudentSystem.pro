QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addstudent.cpp \
    department.cpp \
    departmentlist.cpp \
    displayall.cpp \
    editstudent.cpp \
    main.cpp \
    mainmenu.cpp \
    student.cpp \
    studentlist.cpp \
    studentmodel.cpp

HEADERS += \
    addstudent.h \
    department.h \
    departmentlist.h \
    displayall.h \
    editstudent.h \
    mainmenu.h \
    student.h \
    studentlist.h \
    studentmodel.h

FORMS += \
    addstudent.ui \
    displayall.ui \
    editstudent.ui \
    mainmenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
