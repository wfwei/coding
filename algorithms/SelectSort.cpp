#include<stdio.h>

void prt(int A[], int size){
  int i;
  for(i=0; i<size; i++)
    printf("%d ", A[i]);
  printf("\n");
}

void SelectSort(int A[], int l, int r){
  int i, j, minval, minidx;
  for(i=l; i<r; i++){
    minval=A[i], minidx=i;
    for(j=i+1; j<=r; j++){
      if(A[j]<minval)
        minval=A[j], minidx=j;
    }
    A[minidx]=A[i];
    A[i]=minval;
  }
}

int main(int argc, char* argv[])
{
  int A[13] = {10, 1, 10, 14, 16, 4, 7, 9, 3, 2, 8, 5, 11};
  prt(A, 13);
  SelectSort(A, 0, 12);
  prt(A, 13);
  return 0;
}
