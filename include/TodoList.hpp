#ifndef TODOLIST_H
#define TODOLIST_H

#include <vector>
#include <string>

class TodoList
{
private:
    std::vector<std::string> tasks;

public:
    TodoList();

    // Task operations
    void viewTasks() const;
    void addTask(const std::string &newTask);
    void deleteTask(int index);
    void modifyTask(int index, const std::string &newTask);
    const std::vector<std::string> &getAllTasks() const;

    size_t getTaskCount() const;
};

#endif