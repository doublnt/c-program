// struct_t.h

#ifndef STRUCT_T_H
#define STRUCT_T_H

#include "data_structure/include/base_include.h"
#include "hashmap.h"

typedef struct treeNode *PtrToNode;

struct treeNode {
    char *val;
    PtrToNode FirstChild;
    PtrToNode NextSibling;
};

struct fraction {
    int32_t numeration;
    int32_t denominator;
    char *c_arr;
};

union quantity {
    short count;
    float weight;
    float volume;
};

struct vector {
    int x;
    int y;
};

typedef unsigned char BYTE;
typedef int *intptr;
typedef char *charstr;
typedef struct fraction Fraction;
typedef union quantity Quantity;
typedef struct vector Vector;

void print_int_star();

int compareHashMap(void *element1, void *element2);

#endif
