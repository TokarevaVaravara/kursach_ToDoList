#include "task.h"
#include "./ui_task.h"
#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>
#include <QTextStream>


Task::Task(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Task)
{
    //создание всех элементов из ui
    ui->setupUi(this);
    setupUi();
    setupShortcuts();
    loadTasksFromFile();
}

Task::~Task()
{
    saveTasksToFile();
    delete ui;
}

void Task::setupUi(){
    ui->btnAdd->setDefault(true);
    ui->listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->listWidget->setDragEnabled(true);
    ui->listWidget->setDragDropMode(QAbstractItemView::InternalMove);
    ui->listWidget->setStyleSheet(
        "QlistWidget::item:selected {background: lightgreen;}"
        "QlistWidget::indicator {width: 20px; height: 20px;}"
        //"QlistWidget::indicator:checked {image: url()}"
        //"QlistWidget::indicator:unchecked {image: url()}"
        );
    ui->txtTask->setPlaceholderText("New task for today...");
}

void Task::setupShortcuts()
{
    connect(ui->txtTask, &QLineEdit::returnPressed, this, &Task::on_btnAdd_clicked);
    //connect(ui->listWidget, &QListWidget::itemChanged, this, &Task::onItemChanged);
}

void Task::loadTasksFromFile(){
    path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "//cpp/kursach/ToDoList/ToDoFile.txt";
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0, "error", file.errorString());
        return;
    }
    QTextStream in(&file);
    while(!in.atEnd()){
        QString taskText = in.readLine();
        if(!taskText.isEmpty()){
            addTaskToList(taskText, false);
        }
    }
    file.close();
}

void Task::saveTasksToFile(){
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)){
        QMessageBox::warning(this, "Error", "Cannot save file:" + file.errorString());
        return;
    }
    QTextStream out(&file);
    for(int i = 0; i < ui->listWidget->count(); ++i){
        out <<ui->listWidget->item(i)->text() << "\n";
    }
    file.close();
}

void Task::addTaskToList(const QString& text, bool checked){
    QListWidgetItem* item = new QListWidgetItem(text, ui->listWidget);
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
    item->setCheckState(checked ? Qt::Checked : Qt::Unchecked);
}

void Task::on_btnAdd_clicked()
{
    if(ui->txtTask->text().isEmpty()){
        ui->txtTask->setFocus();
        return;
    }
    addTaskToList(ui->txtTask->text(), true);
    ui->txtTask->clear();
    ui->txtTask->setFocus();
}

void Task::on_btnRemoveAll_clicked()
{
    if(0 == ui->listWidget->count()){
        QMessageBox::information(this, "Ошибка", "Список пуст");
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation", "Delete all tasks", QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes){
        ui->listWidget->clear();
        QFile file(path);
        if(file.open(QIODevice::WriteOnly | QIODevice::Truncate)){
            file.close();
        }
    }
}

void Task::on_btnRemove_clicked()
{
    QList<QListWidgetItem*> selectedItems = ui->listWidget->selectedItems();

    if(selectedItems.isEmpty()){
        QMessageBox::warning(this, "Ошибка", "Ничего не выбрано!");
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation",
        "Delete these tasks?",
        QMessageBox::Yes | QMessageBox::No
        );

    if(reply == QMessageBox::Yes){
        qDeleteAll(selectedItems);
    }
}

void Task::on_btnDiagram_clicked()
{
    form.show();
}

