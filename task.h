#ifndef TASK_H
#define TASK_H

#include <QMainWindow>
#include <form.h>


#include <QStandardPaths>

QT_BEGIN_NAMESPACE
namespace Ui {
class Task;
}
QT_END_NAMESPACE

class Task : public QMainWindow
{
    Q_OBJECT

public:
    Task(QWidget *parent = nullptr);
    ~Task();

private slots:
    void on_btnAdd_clicked();

    void on_btnRemoveAll_clicked();

    void on_btnRemove_clicked();

    void on_pushButton_clicked();

private:
    Ui::Task *ui;
    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/home/varezhka/Документы/cpp/kursach/ToDoList";
    Form form;
};
#endif // TASK_H
