// struct_t.h

#ifndef STRUCT_T_H
#define STRUCT_T_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

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

struct map {
    int index;
    int value;
};

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef unsigned char BYTE;
typedef int *intptr;
typedef char *charstr;
typedef struct fraction Fraction;
typedef union quantity Quantity;
typedef struct vector Vector;
typedef struct map HashMap;
typedef struct ListNode ListNode;

void print_int_star();

int compareHashMap(void *element1, void *element2);

void print_ListNode(ListNode *arr);

#endif
