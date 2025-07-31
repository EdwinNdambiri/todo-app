#include "FileHandler.hpp"
#include <fstream>
#include <iostream>

void FileHandler::saveToFile(const std::vector<std::string> &tasks, const std::string &fileName)
{
    std::ofstream outFile(fileName);
    if (outFile.is_open())
    {
        for (const auto &task : tasks)
        {
            outFile << task << '\n';
        }
    }
    else
    {
        std::cerr << "Error: Unable to open file for writing: " << fileName << '\n';
    }
}

std::vector<std::string> FileHandler::loadFromFile(const std::string &fileName)
{
    std::vector<std::string> tasks;
    std::ifstream inFile(fileName);

    if (inFile.is_open())
    {
        std::string task;
        while (std::getline(std::cin, task))
        {
            if (!task.empty())
            {
                tasks.push_back(task);
            }
            else
            {
                std::cerr << "Note: No existing task file found (" << fileName << ")\n";
            }
        }
    }
    return tasks;
}
