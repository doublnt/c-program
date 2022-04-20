//
// Created by yinxi on 2022/4/17.
//

#ifndef C_PROGRAM_HASHMAP_H
#define C_PROGRAM_HASHMAP_H

typedef struct HashMap{
    int index;
    int value;
}HashMap;

typedef struct HashSet{
    char value;
}HashSet;

int contains(HashSet **pHashSet, int len, char val);
#endif //C_PROGRAM_HASHMAP_H
