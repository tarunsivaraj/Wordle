
/*
 * All of your code goes in here. You need to finish these functions.
 */

#include <limits.h>


int maximum(int *nums, int len) {
    int temp = nums[0];
    for(int i = 0; i < len; i++){
        if (nums[i] > temp){
            temp = nums[i];
        }
    }
    return temp;
}

int sum_positive(int *nums, int len) {
    int sum = 0;
    for(int i = 0; i < len; i++){
        if (nums[i] > 0) {
            sum = sum + nums[i];
        }
    }
    return sum;
}

int reduce(int *nums, int len, int (*f)(int,int), int initial){
  return 0;
}

int maximum_with_reduce(int *nums, int size) {
  return 0;
}

int sum_positive_with_reduce(int *nums, int size) {
  return 0;
}

int count_negative_with_reduce(int *nums, int size) {
  return 0;
}
