#pragma once
#include <QObject>
#include <vector>
#include "models/task.h"


class CoreApp : public QObject {
    Q_OBJECT
    public:
        explicit CoreApp(QObject* parent = nullptr);
        explicit CoreApp(const std::string& db_url);
        ~CoreApp() override;

        Q_INVOCABLE void addTask(const QString& title, int priority);
        Q_INVOCABLE void deleteTask(int taskId); 
        Q_INVOCABLE void toggleTaskCompletion(int taskId);
        Q_INVOCABLE QList<QVariant> getAllTasks();

        signals:
            void taskAdded(const QVariant& task);
            void taskUpdated(const QVariant& task);
            void taskRemoved(int taskId);
            void errorOccured(const QString& error);
        
        //PIMPL
        private:
            class Impl;
            std::unique_ptr<Impl> pImpl_;

}