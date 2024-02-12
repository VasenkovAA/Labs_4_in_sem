cmake_minimum_required(VERSION 3.5)

project(BinaryTree LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(BinaryTree main.cpp tbinarytree.h tbinarytree.cpp)

install(TARGETS BinaryTree
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
