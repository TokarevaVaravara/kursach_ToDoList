#include "task.h"
#include "./ui_task.h"
#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>


Task::Task(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Task)
{
    ui->setupUi(this);
    ui->btnAdd->setDefault(true); // Enter
    connect(ui->txtTask, &QLineEdit::returnPressed, this, &Task::on_btnAdd_clicked);

    ui->listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);

    path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "//cpp/kursach/ToDoList/ToDoFile.txt";

    QFile file(path);

    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()){
        QListWidgetItem* item = new QListWidgetItem(in.readLine(), ui->listWidget);
        ui->listWidget->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    }

    file.close();

}

Task::~Task()
{
    delete ui;

    QFile file(path);

    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream out(&file);

    for(int i = 0; i < ui->listWidget->count(); ++i){
        out << ui->listWidget->item(i)->text()<<"\n";

    }

    file.close();
}

void Task::on_btnAdd_clicked()
{
    if(ui->txtTask->text().isEmpty()){
        ui->txtTask->setFocus();
        return;
    }
    QListWidgetItem* item = new QListWidgetItem(ui->txtTask->text(), ui->listWidget);
    ui->listWidget->addItem(item);
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    ui->txtTask->clear();
    ui->txtTask->setFocus();
}


void Task::on_btnRemoveAll_clicked()
{
    if(0 == ui->listWidget->count()){
        QMessageBox::information(this, "Ошибка", "Список пуст");
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Подтверждение", "Удалить все задачи?", QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes){
        ui->listWidget->clear();
        QFile file(path);
        if(file.open(QIODevice::WriteOnly | QIODevice::Truncate)){
            file.close();
        }
    }
    QListWidgetItem* item = ui->listWidget->takeItem(ui->listWidget->currentRow());
    delete item;
}


void Task::on_btnRemove_clicked()
{
    QList<QListWidgetItem*> selectedItems = ui->listWidget->selectedItems();

    if(selectedItems.isEmpty()){
        QMessageBox::warning(this, "Ошибка", "Ничего не выбрано!");
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Подтверждение",
        "Удалить выбранные задачи?",
        QMessageBox::Yes | QMessageBox::No
        );

    if(reply == QMessageBox::Yes){
        qDeleteAll(selectedItems);
    }
}


void Task::on_pushButton_clicked()
{
    form.show();
}

