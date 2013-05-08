/**
 * filter k largest number use min-heap
 */
#include<stdio.h>
#include<stdlib.h>
#define MIN -1

void swap(int *a, int *b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

void heapify(int AK[], int k){
  int idx = 0, left, right, min; 
  while(idx<k){
    left = idx*2;
    right = idx*2 + 1;
    if(left<k){
      min = left;
      if(right<k && AK[right]<AK[left])
        min = right; 
      if(AK[min]<AK[idx]){
        swap(AK+min, AK+idx);
        idx = min;
        continue;
      }
    }
    break;
  }
}

int* maxKnum(int A[], int len, int k){
  int* AK = (int *)malloc(k*sizeof(int));
  int i;
  for(i=0; i<k; i++)
    AK[i] = MIN;
  for(i=0; i<len; i++){
    if(A[i]>AK[0]){
      AK[0] = A[i];
      heapify(AK, k); 
    }
  }
  return AK;
}

int main(){
  int nums[] = {2, 3, 8, 4, 1, 5, 6, 7};
  int i, k = 3, len=5;
  int* res = maxKnum(nums, len, k);
  for(i=0; i<k; i++)
    printf("%d  ", res[i]);
  printf("\n");
}
