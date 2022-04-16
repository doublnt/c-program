/*
	Author: Yin Xi;
	Date: 2022/02/12
	Info: Practice c language basic grammar.
*/

// preprocessor define.

#include "leetcode.h"

void test_listNode() {
    int arr[5] = {1, 2, 3, 4, 5};
    ListNode *l1 = createListNode(arr, 5);
    printListNode(l1);

    ListNode *root = malloc(sizeof(ListNode));
    root->val = 100;

    ListNode *positionNode = malloc(sizeof(ListNode));
    positionNode->val = 200;
    positionNode->next = NULL;

    root->next = positionNode;
    printListNode(root);

    positionNode = insertBefore(300, root, positionNode);
    positionNode = insertBefore(301, root, positionNode);
    printListNode(root);

    positionNode = insertAfter(400, root, positionNode);
    positionNode = insertAfter(401, root, positionNode);
    printListNode(root);
}

void test_array() {
    int size_z = 3;
    int *size_pointer = &size_z;

    int v1[3][3] = {
            {
                    2, 1, 1
            },
            {
                    1, 1, 0
            },
            {
                    0, 1, 1
            }
    };
    int *v1_pointer = &v1[0][0];
    int **arr_arr = &v1_pointer;

    int val = orangesRotting2(arr_arr, size_z, size_pointer);
    printf("%d\n", val);

    int val2 = orangesRotting(arr_arr, size_z, size_pointer);
    printf("%\n", val2);

    int target = 9;
    int a[5] = {1, 2, 3, 4, 5};
    int *a3 = &a[0];
    int *length = &target;

    int *a2 = twoSum2(a3, 5, target, length);
    print_int_star(a2, 2);

    int *a4 = twoSum(a3, 5, target, length);
    print_int_star(a4, 2);

}

int main(int argc, char *argv[]) {
    int arr[1] = {0};
    int arr2[1] = {0};

    ListNode *l1 = createListNode(arr, 1);
    ListNode *l2 = createListNode(arr2, 1);

    ListNode *l3 = addTwoNumbers(l1, l2);
    printListNode(l3);

    return 0;
}