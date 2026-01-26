cmake_minimum_required(VERSION 4.1)
project(assignment_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(assignment_1 main.cpp
        DLinkedList.cpp
        DLinkedListTest.cpp
        GameEntry.cpp
        GameEntryTest.cpp
        Scores.cpp)
