#pragma once
#include "database_manager.h"

class DatabaseInitializer{
    public:
        static std::unique_ptr<DatabaseManager> createConnection(const std::string& connection_str);
};