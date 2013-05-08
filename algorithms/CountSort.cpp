#include<stdio.h>

void countSort(int A[], int len, const int maxN){
  if(A==NULL || len<=0)
    return;
  int num[maxN+1];
  int i, j;
  for(i=0; i<=maxN; i++)
     num[i] = 0;
  for(i=0; i<len; i++)
    num[A[i]] ++;
  for(i=0, j=0; i<=maxN && j<len; i++){
    while(num[i]>0){
      A[j++] = i;
      num[i]--;
    }
  }
}

void prt(int A[], int len){
  int i=0;
  for(i=0; i<len; i++)
    printf("%d ", A[i]);
  printf("\n");
}

int main(){
  int A[]={10,22, 1, 3, 22, 4, 5, 10};
  prt(A, 8);
  countSort(A, 8, 30);
  prt(A, 8);
  return 0;
}
