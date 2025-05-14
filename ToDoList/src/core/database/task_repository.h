#pragma once
#include <memory>
#include <vector>
#include <pqxx/pqxx>
#include "models/task.h"

class TaskRepository{
    public:
        TaskRepository() = default;
        explicit TaskRepository(pqxx::connection& connection);
        virtual ~TaskRepository() = default;
        //CRUD
        virtual int addTask(const Task& task) ;
        virtual bool deleteTask(int taskId);
        virtual bool updateTask(const Task& task);
        virtual std::optional<Task> getTaskById(int taskId) const;
        virtual std::vector<Task> getAllTasks() const;
};