#ifndef LEETCODE_H
#define LEETCODE_H

#include "struct_t.h"
#include "data_structure/include/list_node.h"

int *twoSum(int *nums, int numsSize, int target, int *returnSize);

int *twoSum2(int *nums, int numsSize, int target, int *returnSize);

int orangesRotting(int **grid, int gridSize, int *gridColSize);

int orangesRotting2(int **grid, int gridSize, int *gridColSize);

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

#endif