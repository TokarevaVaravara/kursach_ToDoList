#include "postgre_repository.h"

PostgreRepository::PostgreRepository(pqxx::connection& connection)
    :connection_(connection){
    if(!connection_.is_open()){
        throw std::runtime_error("Can't reach database connection");
    }
}

int PostgreRepository::addTask(const Task& task){
    pqxx::work txn(connection_);
    auto result = txn.exec_params(
        "INSERT INTO tasks (title, priority, status) VALUES {$1,$2,$3} RETURNING id",
        task.title(),
        static_cast<int>(task.priority()),
        static_cast<int>(task.status())
    );
    txn.commit();
    return result[0]["id"].as<int>();
}

bool PostgreRepository::updateTask(const Task& task){
    pqxx::work txn(connection_);
    auto result = txn.exec_params(
        "INSERT tasks SET title = $1, priority = $2, status = $3 WHERE id = $4",
        task.title(),
        static_cast<int>(task.priority()),
        static_cast<int>(task.status()),
        task.id()
    );
    txn.commit();
    return result.affected_rows() > 0; //возвращает кол-во изменённых строк
}

bool PostgreRepository::deleteTask(int taskId){
    pqxx::work txn(connection_);
    auto result = txn.exec_params(
        "DELETE FROM tasks WHERE id = $1",
        taskId
    );
    txn.commit();
    return result.affected_rows() > 0;
}

std::optional<Task> PostgreRepository::getTaskById(int taskId) const{
    try{
    pqxx::read_transaction txn(connection_);
    auto result = txn.exec_params(
        "SELECT id, title, priority, status, created_at FROM tasks WHERE id = $1",
        taskId
    );
    if(result.empty()){
        return std::nullopt;
    }
    return resultToTask(result[0]);
    } catch (const pqxx::sql_error& e){
        throw std::runtime_error("Database error: " + std::string(e.what()));
    }
}

std::vector<Task> PostgreRepository::getAllTasks() const{
    std::vector<Task> tasks;
    pqxx::read_transaction txn(connection_);
    auto result = txn.exec("SELECT id, title, priority, status, created_at FROM tasks");
    for (const auto& row : result){
        tasks.push_back(resultToTask(row));
    }

}

Task PostgreRepository::resultToTask(const pqxx::row& row) const{
    return Task(
        row["id"].as<int>(),
        row["title"].as<std::string>(),
        static_cast<TaskPriority>(row["priority"].as<int>()),
        static_cast<TaskStatus>(row["status"].as<int>()),
        row["created_at"].as<std::chrono::system_clock::time_point>()
    );
}