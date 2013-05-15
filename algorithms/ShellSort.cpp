#include<stdio.h>
#define SIZE 12 


void prt(int A[], int size){
  int i;
  for(i=0; i<size; i++)
    printf("%d ", A[i]);
  printf("\n");
}

void ShellSort(int A[], int s, int e){
  int i, j, tmp, inc;
  for(inc=(e-s)/2; inc>0; inc/=2){
    prt(A, e-s+1);
    printf("inc:%d\n", inc);
    for(i=inc+s; i<=e; i++){
      tmp = A[i];
      j = i;
      while(j-inc>=s && A[j]<A[j-inc]){
        A[j] = A[j-inc];
        j-=inc;
      }
      A[j] = tmp;
    }
  }
}
int main(int argc, char* argv[])
{
  int A[SIZE] = {1, 10, 14, 16, 4, 7, 9, 3, 2, 8, 5, 11};
  ShellSort(A, 0, SIZE-1);
  prt(A, SIZE);
  return 0;
}
