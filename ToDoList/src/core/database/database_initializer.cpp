#include "database_initializer.h"
#include <stdexcept>

std::unique_ptr<DatabaseManager> DatabaseInitializer::createConnection(const std::string& conn_str){
    auto db = std::make_unique<DatabaseManager>(conn_str);
    db->execute("SELECT 1");
    return db;
} 