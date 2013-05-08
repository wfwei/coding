#include<stdio.h>

//搜索A[]中第一个比val大的数
int BinarySearchUpperBound(int A[], int low, int high, int val){
  if(high<low||val>=A[high])
    return -1;
  int mid;
  while(low<high){
    mid = (low+high)/2;
    if(A[mid]<=val)
      low = mid+1;
    else
      high = mid;
  }
  return high;
}

//搜索A[]中第一个比val小的数
int BinarySearchLowerBound(int A[], int low, int high, int val){
  if(high<low||val<=A[low])
    return -1;
  int mid;
  while(low<high){
    mid = (low+high+1)/2; // pay attention here!!!
    if(A[mid]>=val)
      high = mid-1;
    else
      low = mid;
  }
  return low;
}

int main(){
  int A[5]={2, 3, 5, 5, 10};
  int num = 5;
  printf("%d\n", BinarySearchUpperBound(A, 0, 4, num));
  printf("%d\n", BinarySearchLowerBound(A, 0, 4, num));
  printf("%d appear counts: %d", num, BinarySearchUpperBound(A, 0, 4, num)-BinarySearchLowerBound(A, 0, 4, num)-1);
}

