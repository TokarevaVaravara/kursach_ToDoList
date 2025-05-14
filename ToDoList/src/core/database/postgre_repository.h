#pragma once
#include <pqxx/pqxx>
#include "task_repository.h"

class PostgreRepository : public TaskRepository{
    public:
        explicit PostgreRepository(pqxx::connection& connection);
        //CRUD
        int addTask(const Task& task) override;
        bool deleteTask(int taskId) override;
        bool updateTask(const Task& task) override;
        std::vector<Task> getAllTasks() const override;
        std::optional<Task> getTaskById(int taskId) const override;
    private:
            Task resultToTask(const pqxx::row&) const;
            pqxx::connection& connection_;

            static constexpr const char* SQL_ADD_TASK = "INSERT INTO tasks (title, priority, status) VALUES ($1, $2, $3) RETURNING id";
            static constexpr const char* SQL_GET_ALL_TASKS = "SELECT id, title, priority, status, created_at FROM tasks";
};