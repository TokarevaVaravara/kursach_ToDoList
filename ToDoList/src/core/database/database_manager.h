#pragma once
#include <pqxx/pqxx>
#include <string>
#include <stdexcept>

class DatabaseManager{
    public:
        //явное подключение к БД
        DatabaseManager(const std::string& connection_string);
        //единственность соединения
        DatabaseManager(const DatabaseManager&) = delete;
        DatabaseManager& operator=(const DatabaseManager&) = delete;
        //SQL-запрос без результата
        void execute(const std::string& sql);

        pqxx::result query(const std::string& sql);

        pqxx::work beginTransaction();

        bool isConnected() const;
    private:
        std::unique_ptr<pqxx::connection> connection_;
};