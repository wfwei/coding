#include<stdio.h>

//搜索A[]中最后一个值为val坐标
int BinarySearchUpperBound(int A[], int low, int high, int val){
  while(low<high){
    int mid = low + (high-low+1)/2;
    if(A[mid] == val)
      low = mid;
    else if(A[mid] < val)
      low = mid+1;
    else
      high = mid-1;
  }
  if(A[high]==val)
    return high;
  else
    return -1;
}

//搜索A[]中第一个值为val的数
int BinarySearchLowerBound(int A[], int low, int high, int val){
  while(low<high){
    int mid = low + (high-low)/2;
    if(A[mid]==val)
      high = mid;
    else if(A[mid]>val)
      high = mid-1;
    else
      low = mid+1;
  }
  if(A[low]==val)
    return low;
  else
    return -1;
}

int main(){
  int A[5]={5, 5, 5, 5, 5};
  int num = 5;
  printf("%d\n", BinarySearchUpperBound(A, 0, 4, num));
  printf("%d\n", BinarySearchLowerBound(A, 0, 4, num));
  printf("%d appear counts: %d", num, BinarySearchUpperBound(A, 0, 4, num)-BinarySearchLowerBound(A, 0, 4, num)+1);
}

