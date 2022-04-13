//
// Created by yinxi on 2022/4/9.
//

#ifndef C_PROGRAM_LIST_NODE_H
#define C_PROGRAM_LIST_NODE_H

#include "base_include.h"

/*
 * 有一个 root 节点 的 ListNode
 */
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

/*
 * 打印 链表
 */
void printListNode(ListNode *listNode);

/*
 * 根据 arr 数组 和 length，创建 链表
 */
ListNode *createListNode(int *arr, int length);

/*
 * 向后插入
 */
ListNode *insertAfter(int val, ListNode *list, ListNode *position);

/*
 * 向前插入
 */
ListNode *insertBefore(int val, ListNode *list, ListNode *position);

/*
 * 删除
 */
void deleteNode(int x, ListNode *list);

/*
 * 清空 链表
 */
void freeListNode(ListNode *listNode);

/*
 * 根据 value，查找 链表
 */
ListNode *findListNode(ListNode *listNode, int value);

#endif //C_PROGRAM_LIST_NODE_H
