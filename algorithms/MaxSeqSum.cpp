/**
 * max sum of sequential numbers
 */
#include<stdio.h>
#include<stdlib.h>

int maxSeqSum(int* nums, int len){
  int i;
  int sum=-1, max=0;
  if(nums==NULL)
    return -1;
  for(i=0; i<len; i++){
    sum += nums[i];
    if(sum>max)
      max = sum;
    if(sum<0)
      sum = 0;
  }
  return max;
}

int main(){
  int nums[] = {2, -3, 8, -4, 1, 5, -6, 7};
  int len=8;
  int res = maxSeqSum(nums, len);
  printf("%d\n", res);
}
