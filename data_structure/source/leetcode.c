#include "data_structure/include/leetcode.h"

int orangesRotting(int **grid, int gridSize, const int *gridColSize) {
    int minutes = 0;
    int loopCount = 0;

    while (1) {
        for (uint8_t i = 0; i < gridSize; ++i) {
            for (uint8_t j = 0; j < *gridColSize; ++j) {
                if (grid[i][j] == 2) {
                    uint8_t check = 0;
                    if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                        grid[i][j - 1] = 2;
                        check = 1;
                    }

                    if (j + 1 < *gridColSize && grid[i][j + 1] == 1) {
                        grid[i][j + 1] = 2;
                        check = 1;
                    }

                    if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                        grid[i - 1][j] = 2;
                        check = 1;
                    }

                    if (i + 1 < gridSize && grid[i + 1][j] == 1) {
                        grid[i + 1][j] = 2;
                        check = 1;
                    }

                    if (check == 1) {
                        minutes++;
                    }
                }
            }
        }

        uint8_t shouldBreak = 1;
        for (uint8_t i = 0; i < gridSize; ++i) {
            for (uint8_t j = 0; j < *gridColSize; ++j) {
                if (grid[i][j] == 1) {
                    shouldBreak = 0;
                    break;
                }
            }
        }

        if (shouldBreak == 1) {
            break;
        }

        if (loopCount == gridSize * (*(gridColSize)) - 1) {
            return -1;
        }

        loopCount++;
    }

    return minutes;
}

int orangesRotting2(int **grid, int gridSize, const int *gridColSize) {
    int length = gridSize * (*gridColSize);
    Vector arr[length];

    // First filter the bad orange then cache index to local array.
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < *gridColSize; ++j) {
            int currentIndex = (*gridColSize) * i + j;
            int val = *((*grid) + currentIndex);
            if (val == 2) {
                Vector temp = {.x = i, .y = j};
                arr[currentIndex] = temp;
            } else {
                Vector temp = {.x = -1, .y = -1};
                arr[currentIndex] = temp;
            }
        }
    }

    // Calculate the total minutes used to make all orange bad.
    int minutes = 0;
    for (int i = 0; i < length; ++i) {
        Vector v = arr[i];
        int arr_index = i;
        bool isExistGoodOrange = false;

        if (v.x != -1 && v.y != -1) {
            // Left
            int index = (*gridColSize) * v.x + v.y - 1;
            if (index >= 0 && v.y - 1 >= 0 && *((*grid) + index) == 1) {
                *((*grid) + index) = 2;

                Vector temp = {.x = v.x, .y = v.y - 1};
                arr[++arr_index] = temp;
            }

            // Right
            index = (*gridColSize) * v.x + v.y + 1;
            if (index >= 0 && v.y + 1 < gridSize && *((*grid) + index) == 1) {
                *((*grid) + index) = 2;

                Vector temp = {.x = v.x, .y = v.y + 1};
                arr[++arr_index] = temp;
            }

            // Top
            index = (*gridColSize) * (v.x - 1) + v.y;
            if (index >= 0 && v.x - 1 > 0 && *((*grid) + index) == 1) {
                *((*grid) + index) = 2;

                Vector temp = {.x = v.x - 1, .y = v.y};
                arr[++arr_index] = temp;
            }

            // Bottom
            index = (*gridColSize) * (v.x + 1) + v.y;
            if (index >= 0 && v.x + 1 < *gridColSize && *((*grid) + index) == 1) {
                *((*grid) + index) = 2;

                Vector temp = {.x = v.x + 1, .y = v.y};
                arr[++arr_index] = temp;
            }

            // Search current array check whether exist bad orange.
            for (int i = 0; i < gridSize; ++i) {
                for (int j = 0; j < *gridColSize; ++j) {
                    int currentIndex = (*gridColSize) * i + j;
                    if (*((*grid) + currentIndex) == 1) {
                        minutes++;
                        isExistGoodOrange = true;
                        break;
                    }
                }

                if (isExistGoodOrange) {
                    break;
                }
            }

            if (!isExistGoodOrange) {
                return minutes;
            }
        } else {
            for (int i = 0; i < gridSize; ++i) {
                for (int j = 0; j < *gridColSize; ++j) {
                    int currentIndex = (*gridColSize) * i + j;
                    if (*((*grid) + currentIndex) == 1) {
                        minutes++;
                        isExistGoodOrange = true;
                        break;
                    }
                }

                if (isExistGoodOrange) {
                    break;
                }
            }

            if (isExistGoodOrange) {
                return -1;
            }
        }
    }

    if (0 == minutes) {
        return -1;
    }

    return minutes;
}

int *twoSum(const int *nums, int numsSize, int target, int *returnSize) {
    returnSize = malloc(sizeof(int));
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                (*returnSize) = 2;
                int *a = malloc(sizeof(int) * 2);
                a[0] = i;
                a[1] = j;

                return a;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}

int *twoSum2(const int *nums, int numsSize, int target, int *returnSize) {
    returnSize = malloc(sizeof(int));
    *returnSize = 2;

    HashMap *map = (HashMap *) malloc(sizeof(HashMap) * numsSize);
    int i;

    for (i = 0; i < numsSize; ++i) {
        map[i].index = i;
        map[i].value = nums[i];
    }

    qsort(map, numsSize, sizeof(HashMap), compareHashMap);

    int leftIndex = 0;
    int rightIndex = numsSize - 1;

    int *returnNums = (int *) malloc(sizeof(int) * 2);

    while (leftIndex < rightIndex) {
        if (target == (map[leftIndex].value + map[rightIndex].value)) {
            returnNums[0] = map[leftIndex].index;
            returnNums[1] = map[rightIndex].index;

            break;
        } else if (target < (map[leftIndex].value + map[rightIndex].value)) {
            rightIndex--;
        } else {
            leftIndex++;
        }
    }

    return returnNums;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (l1 == NULL || l2 == NULL) {
        return NULL;
    }

    ListNode *root = (ListNode *) malloc(sizeof(ListNode));
    int isUpVal = 0;
    int val = l1->val + l2->val;

    if (val + isUpVal - 10 >= 0) {
        isUpVal = (l1->val + l2->val) / 10;
        val = val - 10;
    }

    root->val = val;
    root->next = NULL;

    l1 = l1->next;
    l2 = l2->next;

    while (l1 != NULL || l2 != NULL) {
        if (l1 == NULL) {
            while (l2 != NULL) {
                val = isUpVal + l2->val;

                if (val >= 10) {
                    isUpVal = val / 10;
                    val -= 10;
                } else {
                    isUpVal = 0;
                }
                insert_to_tail(val, root);

                l2 = l2->next;
            }
            break;
        } else if (l2 == NULL) {
            while (l1 != NULL) {
                val = isUpVal + l1->val;

                if (val >= 10) {
                    isUpVal = val / 10;
                    val -= 10;
                } else {
                    isUpVal = 0;
                }
                insert_to_tail(val, root);

                l1 = l1->next;
            }
            break;
        }

        val = l1->val + l2->val + isUpVal;

        if (isUpVal + l1->val + l2->val - 10 >= 0) {
            val = isUpVal + l1->val + l2->val - 10;
            isUpVal = (isUpVal + l1->val + l2->val) / 10;
        } else {
            isUpVal = 0;
        }

        insert_to_tail(val, root);
        l1 = l1->next;
        l2 = l2->next;
    }

    if (isUpVal != 0) {
        insert_to_tail(isUpVal, root);
    }

    return root;
}

void initial_hashSet_to_empty(HashSet *hashSet, int len) {
    for (int i = 0; i < len - 1; ++i) {
        hashSet[i].value = '\0';
    }
}

int lengthOfLongestSubstring(char *s) {
    int len = get_str_length(s);
    HashSet *hashSet = (HashSet *) malloc(sizeof(HashSet));

    int i = 0;
    int j = 0;
    int count = 0;
    int setIndex = 0;
    int maxLen = 0;

    int hashSetCount = 1;

    while (i < len && j < len) {
        if (contains(&hashSet, count, s[j])) {
            i++;
            j = i;
            setIndex = 0;

            if (count > maxLen) {
                maxLen = count;
            }
            initial_hashSet_to_empty(hashSet, count);
            count = 0;
        } else {
            if (count > hashSetCount - 1) {
                hashSetCount++;

                // 不能直接 写 realloc 不赋值
                hashSet = realloc(hashSet, hashSetCount);
            }

            hashSet[setIndex++].value = s[j];
            count++;

            j++;
        }
    }

    if (count > maxLen) {
        return count;
    }

    return maxLen;
}
