#include<stdio.h>

int rBinarySearch(int A[], int s, int e, int val){
  int mid = s + (e-s)/2;
  if(A[mid] == val)
    return mid;
  if(s>=e)
    return -1;
  if(A[mid] > val)
    return rBinarySearch(A, s, mid-1, val);
  else
    return rBinarySearch(A, mid+1, e, val);
}

int BinarySearch(int A[], int s, int e, int val){
  while(s<=e){
    int mid = s + (e-s)/2;
    if(A[mid] == val)
      return mid;
    if(A[mid]<val)
      s = mid + 1;
    else
      e = mid - 1;
  }
  return -1;
}

int main(){
  int A[5]={2, 3, 5, 6, 10};
  printf("%d", BinarySearch(A, 0, 4, 2));
}
