cmake_minimum_required(VERSION 3.21)
project(c_program C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(c_program
        data_structure/source/struct_t.c
        data_structure/include/struct_t.h
        data_structure/source/leetcode.c
        data_structure/include/leetcode.h
        main.c
        data_structure/source/search_tree.c
        data_structure/include/search_tree.h
        data_structure/include/list_node.h data_structure/source/list_node.c data_structure/include/base_include.h data_structure/include/str_oper.h data_structure/source/str_oper.c data_structure/source/hashmap.c data_structure/include/hashmap.h)
