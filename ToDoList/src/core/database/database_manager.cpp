#include "database_manager.h"

DatabaseManager::DatabaseManager(const std::string& connection_string){
    try{
        connection_ = std::make_unique<pqxx::connection>(connection_string);
        if(!connection_->is_open()){
            throw std::runtime_error("Can't connect PostgreSQL:");
        }
        pqxx::nontransaction check(*connection_);
        check.exec("SELECT 1");
    } catch (const pqxx::sql_error& e){
        throw std::runtime_error("Can't connect PostgreSQL:" + std::string(e.what()));
    }    
}  
void DatabaseManager::execute(const std::string& sql){
    pqxx::work txn(*connection_); //транзакция
    txn.exec(sql); //sql-запрос
    txn.commit(); //подтверждение
}

pqxx::result DatabaseManager::query(const std::string& sql){
    pqxx::read_transaction txn(*connection_);
    return txn.exec(sql);
}

pqxx::work DatabaseManager::beginTransaction(){
    return pqxx::work(*connection_);
}

bool DatabaseManager::isConnected() const{
    return connection_ && connection_->is_open();
}