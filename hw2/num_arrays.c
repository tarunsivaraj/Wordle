
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
    for(int i = 0; i < len; i++) {
        initial = f(initial, nums[i]);
    }
    return initial;
}

int helper1(int first, int second) {
    if (second > first) {
        return second;
    } else {
        return first;
    }
    
}

int helper2(int first, int second) {
    if (first > 0 && second > 0) {
        return first + second;
    } else {
        if (first > 0) {
            return first;
        }
        else if (second > 0) {
            return second;
        } else {
            return 0;
        }
        
    
    }
}

int helper3(int first, int second) {
    if (second < 0) {
        first += 1;
    }
    return first;

}



int maximum_with_reduce(int *nums, int size) {
    return reduce(nums, size, helper1, INT_MIN);
}

int sum_positive_with_reduce(int *nums, int size) {
    return reduce(nums, size, helper2, 0);
 
}

int count_negative_with_reduce(int *nums, int size) {
    return reduce(nums, size, helper3, 0);
}

