#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "TodoList.hpp"
#include "FileHandler.hpp"

void displayMenu()
{
    std::cout << "\nWelcome to your todo list.\n"
              << "1. View tasks\n"
              << "2. Add a task\n"
              << "3. Delete a task\n"
              << "4. Modify a task\n"
              << "5. Exit\n";
}

int main()
{
    const std::string fileName{"TodoList.txt"};
    TodoList todoList;

    // Load initial tasks
    std::vector<std::string> loadedTasks{FileHandler::loadFromFile(fileName)};

    for (const auto &task : loadedTasks)
    {
        todoList.addTask(task);
    }

    if (todoList.getTaskCount() == 0)
    {
        std::string defaultTask{"Preparing breakfast"};
        todoList.addTask(defaultTask);
        FileHandler::saveToFile({defaultTask}, fileName);
    }

    int choice{0};
    do
    {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            std::cout << "\nHere are your tasks:\n";
            todoList.viewTasks();
            break;

        case 2:
        {
            std::cout << "\nEnter the task to be added: \n";
            std::string newTask;
            std::getline(std::cin, newTask);
            todoList.addTask(newTask);
            FileHandler::saveToFile(todoList.getAllTasks(), fileName);
            break;
        }

        case 3:
        {
            std::cout << "\nHere are your tasks, please select the task to be deleted: \n";
            todoList.viewTasks();

            if (todoList.getTaskCount() > 0)
            {
                std::cout << "\nEnter task number to be deleted: ";
                int index{0};
                std::cin >> index;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                todoList.deleteTask(index);
                FileHandler::saveToFile(todoList.getAllTasks(), fileName);
            }

            break;
        }

        case 4:
            std::cout << "\nHere are your tasks:\n";
            todoList.viewTasks();

            if (todoList.getTaskCount() > 0)
            {
                std::cout << "\nEnter task number to modify: ";
                int index{0};
                std::cin >> index;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter new task description: ";
                std::string newTask;
                std::getline(std::cin, newTask);

                todoList.modifyTask(index, newTask);
                FileHandler::saveToFile(todoList.getAllTasks(), fileName);
                std::cout << "Task updated successfully!\n";
            }

            break;
        case 5:
            std::cout << "Exiting program. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}