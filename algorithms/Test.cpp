#include<stdio.h>

int main(){
  int a = 1<<15; 
  short b = (short)a;
  printf("a:%d\tb:%d",a, b);
}
