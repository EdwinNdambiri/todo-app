#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include <string>

class FileHandler
{
public:
    static void saveToFile(const std::vector<std::string> &tasks, const std::string &fileName);
    static std::vector<std::string> loadFromFile(const std::string &fileName);
};

#endif