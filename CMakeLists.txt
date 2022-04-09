cmake_minimum_required(VERSION 3.21)
project(c_program C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(c_program
        struct_t.c
        struct_t.h
        leetcode.c
        leetcode.h
        main.c
        data_structure/source/search_tree.c
        data_structure/include/search_tree.h
        data_structure/include/list_node.h)
