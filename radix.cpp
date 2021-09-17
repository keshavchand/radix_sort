#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RANDOM_NUMS_LEN 1000
void radix_sort(unsigned int * nums, size_t len){
  unsigned int mask = 1;

  unsigned int *zero = (unsigned int*)malloc(sizeof(*zero)* len);
  unsigned int *one = (unsigned int*)malloc(sizeof(*one)* len);

  //unsigned int *final_nums = (unsigned int*)malloc(len);

  while (mask){
    int zero_idx = 0;
    int one_idx = 0;

    for (int idx = 0; idx < len; idx++){
      unsigned int num = nums[idx] & mask;
      if (num) one[one_idx++]   = nums[idx];
      else     zero[zero_idx++] = nums[idx];
    }
    
    int nums_idx = 0;
    for (int idx = 0; idx < zero_idx; idx++){
      nums[nums_idx++] = zero[idx];
    }

    for (int idx = 0; idx < one_idx; idx++){
      nums[nums_idx++] = one[idx];
    }

    mask <<= 1;
  }

  free(zero);
  free(one);
}

int main(){
  unsigned int* random_nums = (unsigned int*) malloc(sizeof(*random_nums) * RANDOM_NUMS_LEN);
  for (int i = 0; i < RANDOM_NUMS_LEN; i++) random_nums[i] = RANDOM_NUMS_LEN - i;
  radix_sort(random_nums, RANDOM_NUMS_LEN);
  free(random_nums);
}
