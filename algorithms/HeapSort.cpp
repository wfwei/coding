#include<stdio.h>

int left(int i){
  return i*2+1;
}

int right(int i){
  return i*2+2;
}

void swap(int* a, int* b){
  *a = *a^*b;
  *b = *a^*b;
  *a = *a^*b;
}

void maxHeapify(int A[], int i, int size){
  int l=left(i), r=right(i);
  int largest;

  if(l<size && A[l]>A[i])
    largest = l; 
  else
    largest = i;
  if(r<size && A[r]>A[largest])
    largest = r;

  if(largest!=i){
    swap(A+i, A+largest);
    maxHeapify(A, largest, size);
  }
} 

void buildMaxHeap(int A[], int size){
  int i;
  for(i=(size-2)/2; i>=0; i--)
    maxHeapify(A, i, size);
}

void prt(char* title, int A[], int size){
  int i;
  printf("%s\t", title);
  for(i=0; i<size; i++)
    printf("%d ", A[i]);
  printf("\n");
}

void heapSort(int A[], int size){
  buildMaxHeap(A, size);
  int i;
  for(i=size-1; i>=0; i--){
    swap(A+i, A);
    maxHeapify(A, 0, i);
  }
}

int main(){
  int A[5]={2, 3, 5, 6, 10};
  prt("original:", A, 5);
  heapSort(A, 5);
  prt("after sort:",A, 5);
}
