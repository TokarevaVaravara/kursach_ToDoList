#pragma once
#include <string>
#include <chrono>

enum class TaskPriority {Low, Medium, High};
enum class TaskStatus {Pending, Completed, Archived};

class Task{
    public:
        Task() = default;
        Task(std::string title, TaskPriority priority)
            : id_(-1),
             title_(std::move(title)),
             priority_(priority),
             status_(TaskStatus::Pending),
             created_at_(std::chrono::system_clock::now()) {}
    //для сериализации
        Task(int id, std::string title, TaskPriority priority, TaskStatus status, std::chrono::system_clock::time_point created_at)
            : id_(id),
            title_(std::move(title)),
            priority_(priority),
            status_(status),
            created_at_(created_at) {}

    //геттеры
        int id() const {return id_;};
        const std::string& title() const {return title_;}
        TaskPriority priority() const {return priority_;}
        TaskStatus status() const {return status_;}
        auto createdAt() const {return created_at_;};
    //сеттеры
        void setTitle(const std::string& new_title){
            if(!new_title.empty()){
                title_ = new_title;
            }
        };
        void setPriority(TaskPriority new_priority){
            if((new_priority == TaskPriority::Low) || (new_priority == TaskPriority::Medium) || (new_priority == TaskPriority::High)){
                priority_ = new_priority;
            }
        };
        void setStatus(TaskStatus new_status){
            if((new_status == TaskStatus::Pending) || (new_status == TaskStatus::Archived) || (new_status == TaskStatus::Completed)){
                status_ = new_status;
            }
        };

        bool isValid() const{
            return !title_.empty() && id_ >= -1;
        }
        static bool isValidTitle(const std::string& title){
            return !title.empty() && title.length() <= 200 && title.find('\n') == std::string::npos;
        }
    private:
        int id_ = -1;
        std::string title_;
        TaskPriority priority_ = TaskPriority::Medium;
        TaskStatus status_ = TaskStatus::Pending;
        std::chrono::system_clock::time_point  created_at_;
};