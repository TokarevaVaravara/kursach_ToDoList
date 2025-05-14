/********************************************************************************
** Form generated from reading UI file 'task.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_H
#define UI_TASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Task
{
public:
    QWidget *centralwidget;
    QLineEdit *txtTask;
    QPushButton *btnAdd;
    QPushButton *btnRemove;
    QPushButton *btnRemoveAll;
    QListWidget *listWidget;
    QPushButton *btnDiagram;
    QPushButton *btnSettings;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Task)
    {
        if (Task->objectName().isEmpty())
            Task->setObjectName("Task");
        Task->resize(550, 600);
        centralwidget = new QWidget(Task);
        centralwidget->setObjectName("centralwidget");
        txtTask = new QLineEdit(centralwidget);
        txtTask->setObjectName("txtTask");
        txtTask->setGeometry(QRect(20, 10, 411, 21));
        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName("btnAdd");
        btnAdd->setGeometry(QRect(430, 10, 88, 26));
        btnAdd->setFlat(true);
        btnRemove = new QPushButton(centralwidget);
        btnRemove->setObjectName("btnRemove");
        btnRemove->setGeometry(QRect(20, 470, 88, 26));
        btnRemoveAll = new QPushButton(centralwidget);
        btnRemoveAll->setObjectName("btnRemoveAll");
        btnRemoveAll->setGeometry(QRect(110, 470, 88, 26));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(20, 40, 491, 421));
        btnDiagram = new QPushButton(centralwidget);
        btnDiagram->setObjectName("btnDiagram");
        btnDiagram->setGeometry(QRect(240, 470, 88, 26));
        btnSettings = new QPushButton(centralwidget);
        btnSettings->setObjectName("btnSettings");
        btnSettings->setGeometry(QRect(390, 470, 88, 26));
        Task->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Task);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 550, 23));
        Task->setMenuBar(menubar);
        statusbar = new QStatusBar(Task);
        statusbar->setObjectName("statusbar");
        Task->setStatusBar(statusbar);

        retranslateUi(Task);

        QMetaObject::connectSlotsByName(Task);
    } // setupUi

    void retranslateUi(QMainWindow *Task)
    {
        Task->setWindowTitle(QCoreApplication::translate("Task", "Task", nullptr));
        btnAdd->setText(QCoreApplication::translate("Task", "Add", nullptr));
        btnRemove->setText(QCoreApplication::translate("Task", "Remove", nullptr));
        btnRemoveAll->setText(QCoreApplication::translate("Task", "RemoveAll", nullptr));
        btnDiagram->setText(QCoreApplication::translate("Task", "Diagram", nullptr));
        btnSettings->setText(QCoreApplication::translate("Task", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Task: public Ui_Task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_H
