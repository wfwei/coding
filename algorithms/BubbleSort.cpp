#include<stdio.h>
#define SIZE 100 

void swap(int *a, int *b){
  *a = *a^*b;
  *b = *a^*b;
  *a = *a^*b;
}

// 基本冒泡排序
void BubbleSort(int A[], int l, int h){
  int i;
  while(l<h){
    for(i=l; i<h; i++){
      if(A[i]>A[i+1]){
        swap(&A[i], &A[i+1]);
      }
    }
    h--;
  }
}

// 设置终止标志位（不再有交换时终止）
void BubbleSort1(int A[], int l, int h){
  int i, over;
  while(l<h){
    over = 1;
    for(i=l; i<h; i++){
      if(A[i]>A[i+1]){
        swap(&A[i], &A[i+1]);
        over=0;
      }
    }
    if(over)
      break;
    else
      h--;
  }
}

// 设置终止位，同时记录最后一次交换位置
void BubbleSort2(int A[], int l, int h){
  int i, over, lastSwap;
  while(l<h){
    over = 1;
    lastSwap=l;
    for(i=l; i<h; i++){
      if(A[i]>A[i+1]){
        swap(&A[i], &A[i+1]);
        over=0;
        lastSwap=i;
      }
    }
    if(over)
      break;
    else
      h=lastSwap;
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
  int A[SIZE] = {10, 1, 10, 14, 16, 4, 7, 9, 3, 2, 8, 5, 11};
  BubbleSort2(A, 0, SIZE-1);
  prt(A, SIZE);
  return 0;
}
