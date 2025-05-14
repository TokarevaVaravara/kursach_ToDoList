#ifndef TASK_H
#define TASK_H

#include <form.h>

#include <QMainWindow>
#include <QListWidgetItem>
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
    explicit Task(QWidget *parent = nullptr);
    ~Task();

private slots:
    //CustomModel model;
    //QtreeView* treeView;
    void setupUi();

    void setupShortcuts();

    void loadTasksFromFile();

    void addTaskToList(const QString& text, bool checked);

    void saveTasksToFile();

    void on_btnAdd_clicked();

    void on_btnRemoveAll_clicked();

    void on_btnRemove_clicked();

    void on_btnDiagram_clicked();
private:
    Ui::Task *ui;
    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/home/varezhka/Документы/cpp/kursach/ToDoList";
    Form form;
};
#endif // TASK_H
