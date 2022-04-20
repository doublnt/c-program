//
// Created by yinxi on 2022/4/16.
//

#include "../include/str_oper.h"
#include "../include/base_include.h"

int get_str_length(char *arr) {
    int i = 0;

    while (arr[i] != '\0') {
        ++i;
    }

    return i;
}

