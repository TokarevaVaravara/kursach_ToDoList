#include "src/core/database/database_initializer.h"
#include "src/core/database/postgre_repository.h"
#include "src/core/services/task_service.h"
#include <pqxx/pqxx>
#include <iostream>

int main(){
    try{
        pqxx::connection conn(
            "host=localhost"
            "dbname=kursach"
            "user=Varezhka"
            "password=awesome"
        );
        if(!conn.is_open()){
            throw std::runtime_error("Connection failed");
        }
        PostgreRepository repo(conn);
        TaskService service(repo);
    } catch (const std::exception& e){
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
