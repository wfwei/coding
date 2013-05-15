/**
 * 小根堆
 */

#include<stdio.h>

#define MIN -1;

struct HeapStruct {
  int capacity;
  int size;
  int *elements;
};

typedef struct HeapStruct *PriorityQueue;

void FatalError(char *msg){
  printf("%s", msg);
  exit(1);
}

void Error(char *msg){
  printf("%s", msg);
}

bool isFull(PriorityQueue H){
  if(H->size < H->capacity)
    return 0;
  return 1;
}

bool isEmpty(PriorityQueue H){
  if(H->size == 0)
    return 1;
  return 0;
}

PriorityQueue Init(int capacity){
  PriorityQueue H;

  H = malloc(sizeof(PriorityQueue));
  if(H==NULL)
    FatalError("Out of memory");

  H->elements = malloc(sizeof(int)*(capacity+1));
  if(H->elements==NULL)
    FatalError("Out of memory");

  H->capacity = capacity;
  H->elements[0] = MIN; //哨兵
  H->size = 0;

  return H;
}

/* H->elements[0]是哨兵*/
void Insert(int val, PriorityQueue H){
  int i;
  if(IsFull(H)){
    Error("Priority Queue is full");
    return ;
  }

  H->size ++;

  for(i=H->size; H->elements[i/2]>val; i/=2)
    H->elements[i] = H->elements[i/2];
  H->elements[i] = val;
}

int DeleteMin(PriorityQueue H){
  if(isEmpty(H)){
    Error("Priority Queue is Empty");
    return H->elements[0];
  }

  int minVal = H->elements[1];
  int lastVal = H->elements[H->size--];
  int i;
  for(i=1; i*2<=H->size;){
    int cidx = i*2;
    if(cidx<H->size && H->elements[cidx]>H->elements[cidx+1])
      cidx ++;
    if(lastVal > H->elements[cidx])
      H-elements[i] = H->elements[cidx];
    else
      break;
  }
  H->elements[i] = lastVal;

  return minVal;
}

