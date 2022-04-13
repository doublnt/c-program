//
// Created by yinxi on 2022/4/9.
//

#include "data_structure/include/list_node.h"

void printListNode(ListNode *listNode) {
    while (listNode != NULL) {
        if (listNode->val == NULL) {
            listNode = listNode->next;
            continue;
        }

        printf("%d,", listNode->val);
        listNode = listNode->next;
    }

    printf("\n");
}

ListNode *createListNode(int *arr, int length) {
    ListNode *root = malloc(sizeof(ListNode) * length);
    root->next = NULL;

    int i;
    ListNode *position = root;
    for (i = 0; i < length; ++i) {
        position = insertAfter(arr[i], root, position);
    }

    return root;
}

/*
 * 插入到 position 后面
 */
ListNode *insertAfter(int val, ListNode *list, ListNode *position) {
    if (NULL == list) {
        return NULL;
    }

    ListNode *newNode = malloc(sizeof(ListNode));
    newNode->next = NULL;

    if (list->next == NULL) {
        list->next = newNode;
        list->val = val;

        return list;
    }

    newNode->val = val;

    while (list != NULL) {
        if (list == position) {
            position->next = newNode;
            break;
        }

        list = list->next;
    }

    return newNode;
}

/*
 * 插入到 position 前面
 */
ListNode *insertBefore(int val, ListNode *list, ListNode *position) {
    if (NULL == list) {
        return NULL;
    }

    ListNode *newNode = malloc(sizeof(ListNode));
    newNode->next = NULL;

    if (list->next == NULL) {
        list->next = newNode;
        list->val = val;

        return list;
    }

    newNode->val = val;

    while (list != NULL) {
        if (list == position) {
            newNode->next = list->next;
            list->next = newNode;
            break;
        }

        list = list->next;
    }

    return newNode;
}

void deleteNode(int x, ListNode *list) {
    if (NULL == list) {
        return;
    }

    while (list->next != NULL) {
        if (list->next->val == x) {
            ListNode *tobeDeletedNode = list->next;
            list->next = tobeDeletedNode->next;

            freeListNode(tobeDeletedNode);
            break;
        }

        list = list->next;
    }
}

void freeListNode(ListNode *listNode) {
    listNode->next = NULL;
    listNode = NULL;
}

ListNode *findListNode(ListNode *listNode, int value) {
    if (NULL == listNode) {
        return NULL;
    }

    while (listNode != NULL) {
        if (listNode->val == value) {
            return 1;
        }

        listNode = listNode->next;
    }

    return NULL;
}
