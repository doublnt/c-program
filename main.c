/*
	Author: Yin Xi;
	Date: 2022/02/12
	Info: Practice c language basic grammar.
*/

// preprocessor define.

#include "leetcode.h"

int main(int argc, char *argv[]) {
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

//    int val2 = orangesRotting(arr_arr, size_z, size_pointer);
//    printf("%\n", val2);

    int target = 9;
    int a[5] = {1, 2, 3, 4, 5};
    int *a3 = &a[0];
    int *length;

    int *a2 = twoSum2(a3, 5, 9, length);
    print_int_star(a2, 2);

    int *a4 = twoSum(a3, 5, 9, length);
    print_int_star(a4, 2);


    return 0;
}