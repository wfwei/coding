#include<stdio.h>
// 本程序计算逆序数对个数,http://blog.csdn.net/morewindows/article/details/8029996
int revpair;

void merge(int A[], int s, int m, int e, int tmp[]){
  int s2=m+1, i=0;
  while(s<=m && s2<=e){
    if(A[s]<=A[s2])
      tmp[i++]=A[s++];
    else
      tmp[i++]=A[s2++], revpair+=m-s+1;
  }
  while(s<=m)
    tmp[i++]=A[s++];
  while(s2<=e)
    tmp[i++]=A[s2++];
  while(i)
    A[e--]=tmp[--i];
}

void MergeSort(int A[], int s, int e, int tmp[]){
  if(s>=e)
    return;
  int m=(s+e)/2;
  MergeSort(A, s, m, tmp);
  MergeSort(A, m+1, e, tmp);
  merge(A, s, m, e, tmp);
}

void prt(int A[], int s, int e){
  while(s<=e)
    printf("%d ", A[s++]);
  printf("\n");
}
int main(){
  int A[10] = {1, 7, 2, 9, 6, 4, 5, 3}, tmp[10];
  revpair=0;
  MergeSort(A, 0, 7, tmp);
  prt(A, 0, 7);
  printf("reverse pair count:%d\n", revpair);
  return 1;
}
