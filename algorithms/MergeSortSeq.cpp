#include<stdio.h>

void merge(int A[], int s, int m, int e, int tmp[]){
  int s2=m+1, i=0;
  while(s<=m && s2<=e){
    if(A[s]<=A[s2])
      tmp[i++]=A[s++];
    else
      tmp[i++]=A[s2++];
  }
  while(s<=m)
    tmp[i++]=A[s++];
  while(s2<=e)
    tmp[i++]=A[s2++];
  while(i)
    A[e--]=tmp[--i];
}

void MergeSort(int A[], int s, int e, int tmp[]){
  int k=1, i;
  while(s+k<=e){
    for(i=s; i+k<=e; i+=k+k)
      merge(A, i, i+k-1, i+k+k-1>e?e:i+k+k-1, tmp);
    k+=k;
  }
}

void prt(int A[], int s, int e){
  while(s<=e)
    printf("%d ", A[s++]);
  printf("\n");
}

int main(){
  int A[5] = {2, 1, 1, 6, 4}, tmp[5];
  MergeSort(A, 0, 4, tmp);
  prt(A, 0, 4);
  return 1;
}
