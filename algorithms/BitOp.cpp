#include<stdio.h>

int bitadd(int a, int b){
  int c = a&b;
  int d = a^b;
  if(c>0)
    return bitadd(c<<1, d);
  else
    return d;

}

int bitadd2(int a, int b){
  int tmp;
  while(a>0){
    tmp = a&b;
    b = a^b;
    a = tmp<<1;
  }
  return b;
}

int main(){
  int a=11, b=1;
  printf("%d+%d=%d\n", a, b, bitadd2(a, b));
  printf("-(%d)=%d", b, bitadd(~b, 1));
  return 0;
}
