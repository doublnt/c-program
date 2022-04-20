//
// Created by yinxi on 2022/4/17.
//

#include "data_structure/include/hashmap.h"
#include "data_structure/include/base_include.h"

int contains(HashSet **pHashSet, int len, char val) {
    if ((*pHashSet) == NULL) {
        return 0;
    }

    for (int i = 0; i < len; ++i) {
        if (((*pHashSet) + i)->value == val) {
            return 1;
        }
    }

    return 0;
}