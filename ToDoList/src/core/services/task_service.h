#pragma once
#include "models/task.h"
#include "database/task_repository.h"
#include <vector>
#include <optional>

class TaskService{
    public:
        explicit TaskService(TaskRepository& repository);
        //CRUD
        int createTask(const std::string& title, TaskPriority priority);
        bool updateTask(const Task& task);
        bool deleteTask(int taskId);
        std::optional<Task> getTaskById(int taskId) const;
        std::vector<Task> getAllTasks() const;
    private:
        TaskRepository& repository_;
};