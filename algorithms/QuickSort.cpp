#include<stdio.h>
#define SIZE 100 

void QuickSort(int A[], int l, int r){
  if(r<=l) return;
  int val = A[l], i=l, j=r;
  while(i<j){
    while(A[j]>=val&&j>i)
      j--;
    A[i]=A[j];
    while(A[i]<=val&&i<j)
      i++;
    A[j]=A[i];
  }
  A[i]=val;
  QuickSort(A, l, i-1);
  QuickSort(A, i+1, r);
}

void prt(int A[], int size){
  int i;
  for(i=0; i<size; i++)
    printf("%d ", A[i]);
  printf("\n");
}

int main(int argc, char* argv[])
{
  int A[SIZE] = {10, 1, 10, 14, 16, 4, 7, 9, 3, 2, 8, 5, 11};
  QuickSort(A, 0, SIZE-1);
  prt(A, SIZE);
  return 0;
}
