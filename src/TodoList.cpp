#include <iostream>
#include "TodoList.hpp"

TodoList::TodoList() {}

void TodoList::viewTasks() const
{
    if (tasks.empty())
    {
        std::cout << "No tasks available.\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); i++)
    {
        std::cout << i + 1 << ". " << tasks.at(i) << '\n';
    }
}

void TodoList::addTask(const std::string &newTask)
{
    tasks.push_back(newTask);
}

void TodoList::deleteTask(int index)
{
    if (index > 1 && index <= static_cast<int>(tasks.size()))
    {
        tasks.erase(tasks.begin() + (index - 1));
    }
    else
    {
        std::cout << "Invalid task number!\n";
    }
}

size_t TodoList::getTaskCount() const
{
    return tasks.size();
}

void TodoList::modifyTask(int index, const std::string &newTask)
{
    if (index > 1 && index <= static_cast<int>(tasks.size()))
    {
        tasks[index - 1] = newTask;
    }
    else
    {
        std::cout << "Invalid task number!\n";
    }
}

const std::vector<std::string> &TodoList::getAllTasks() const
{
    return tasks;
}
