#include "core_app.h"
#include "services/task_service.h"
#include "database/database_manager.h"

class CoreApp::Impl{
    public:
        TaskService service_;
        DatabaseManager dbManager_;
};

CoreApp::CoreApp(QObject* parent) 
    : QObject(parent), pImpl_(std::make_unique<Impl>()){
        pImpl_->dbManager_.connect("postgresql...");
}

CoreApp::CoreApp(const std::string& db_url)
    : db_(initDatabase(db_url)),
        task_repo_(db_),
        task_service_(task_repo_){}

void CoreApp::addTask(const QString& title, int priority){
    try{
        Task task = impl_->service_.addTask(title.toStdString(), static_cast<TaskPriority>(priority));
        emit taskAdded(task.toQVariant());
    } catch(const std::exception& e){
        emit errorOccured(QString("Ошибка %1").arg(e.what()));
    }
}

void CoreApp::deleteTask(int taskId){
    
}
