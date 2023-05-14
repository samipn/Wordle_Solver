#include <limits.h>

int maximum(int *nums, int len) {
  int i;
  int max = nums[0]; 
  for (i = 1; i < len; i++) {
    if (nums[i] > max) {
      max = nums[i];
    }
  }
  return max;
}

int sum_positive(int *nums, int len) {
  int i;
  int positiveSum = 0;  
  for(i = 0; i < len; i++){
    if(nums[i] > 0){
      positiveSum += nums[i];
    }
  }
  return positiveSum;
}

int reduce(int *nums, int len, int (*f)(int,int), int initial){
  int result = initial;
  for(int i = 0; i < len; i++) {
    result = f(result, nums[i]); 
  }
  return result;
}

int max_helper(int max, int num) {
  if(max > num) {
    return max;
  }
  else {
    return num;
  }  
}

int sum_positive_helper(int total_sum, int num) {
  if(num > 0) {
    total_sum += num;
  }
  return total_sum; 
}

int count_negative_helper(int total_negatives, int num) {
  if(num < 0){
    total_negatives += 1;
  }
  return total_negatives;
}

int maximum_with_reduce(int *nums, int size) {
  return reduce(nums, size, max_helper, INT_MIN); 
}

int sum_positive_with_reduce(int *nums, int size) {
  return reduce(nums, size, sum_positive_helper, 0);
}

int count_negative_with_reduce(int *nums, int size) {
  return reduce(nums, size, count_negative_helper, 0);
}

