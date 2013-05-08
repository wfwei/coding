#include<stdio.h>

void InsertSort(int A[], int l, int r){
  int i, j, tmp;
  for(i=l+1; i<=r; i++){
    j=i, tmp=A[i];
    while(j>l && A[j-1]>tmp)
      A[j]=A[j-1], j--;
    A[j]=tmp;
  }
}

void prt(int A[], int size){
  int i;
  for(i=0; i<size; i++)
    printf("%d ", A[i]);
  printf("\n");
}

int main(int argc, char* argv[])
{
  int A[13] = {10, 1, 10, 14, 16, 4, 7, 9, 3, 2, 8, 5, 11};
  prt(A, 13);
  InsertSort(A, 0, 12);
  prt(A, 13);
  return 0;
}
