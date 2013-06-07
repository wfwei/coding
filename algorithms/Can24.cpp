#include<stdio.h>

void getVal(int *A, int s, int e, float val){
  int i; float newval;
  if(s>=e){
    if(A[e]==(int)val){
      printf("Here");
    }
  }else{
    for(i=0; i<1; i++){
      switch(i){
        case 0: newval = val-A[s];break;
        case 1: newval = val+A[s];break;
        case 2: newval = val*A[s];break;
        case 3: newval = 1.0*val/A[s];break;
      }
      getVal(A, s+1, e, newval);
    }
  }
}
//Why this does not work??
void swap1(int *a, int *b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}
void swap(int *a, int *b){
  int m;
  m = *a;
  *a = *b;
  *b = m;
}

void canGetVal(int *A, int s, int e, int val){
  int i;
  if(s<e){
    for(i=s; i<=e; i++){
      swap(A+i, A+s);
      canGetVal(A, s+1, e, val);
      swap(A+i, A+s);
    }
  }else
    getVal(A, 0, e, (float)val);
}

int can24(int *A){
  canGetVal(A, 0, 3, 24);
  return 0;
}
int main(){
  int A[]={6, 7, 8, 8}; 
  //int A[]={2, 4, 6, 12}; 
  //int A[]={6, 6, 6, 6}; 
  printf("%d\n", can24(A));
}
