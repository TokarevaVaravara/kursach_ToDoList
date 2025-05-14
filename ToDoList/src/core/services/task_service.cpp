#include "task_service.h"

TaskService::TaskService(TaskRepository& repository)
    : repository_(repository) {}

int TaskService::createTask(const std::string& title, TaskPriority priority){
    if(!isValidTitle(title)){
        throw std::invalid_argument("Incorrect input");
    }
    Task task(title, priority);
    return repository_.addTask(task); //репозиторий сохраняет в БД и возвращает ID
}

bool TaskService::updateTask(const Task& task){
    if(!task.isValid()){
        throw std::invalid_argument("Incorrect input");
    }
    //проверяем существование задачи в БД
    auto existingTask = repository_.getTaskById(task.id());
    if(!existingTask){
        throw std::runtime_error("Can't find task");
    }
    //нельзя менять архивные задачи
    if (existingTask->status() == TaskStatus::Archived || existingTask->status() == TaskStatus::Completed){
        throw std::logic_error("You can't update archived or completed task");
    }
    return repository_.updateTask(task);
}

bool TaskService::deleteTask(int taskId){
    //проверяем существование в БД
    auto existingTask = repository_.getTaskById(taskId);
    if(!existingTask){
        throw std::runtime_error("Can't find task");
    }
    //нельзя удалять архивные задачи
    if (existingTask->status() == TaskStatus::Archived || existingTask->status() == TaskStatus::Completed){
        throw std::logic_error("You can't delete archived or completed task");
    }
    bool isDeleted = repository_.deleteTask(taskId);
    return isDeleted;
}
std::optional<Task> TaskService::getTaskById(int taskId) const{
    //проверяем существование в БД
    auto existingTask = repository_.getTaskById(taskId);
    if(!existingTask){
        throw std::runtime_error("Can't find task");
    }
    return existingTask;
}
std::vector<Task> TaskService::getAllTasks() const{
    auto tasks = repository_.getAllTasks();
    return tasks;
}