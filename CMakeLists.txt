cmake_minimum_required(VERSION 3.10)
project(TodoApp)

set(CMAKE_CXX_STANDARD 17)

# Include header files
include_directories(include)

# Add executable
add_executable(todo_app 
    src/main.cpp
    src/TodoList.cpp
    src/FileHandler.cpp
)

target_include_directories(todo_app PRIVATE include)