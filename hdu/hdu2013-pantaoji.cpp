#include<stdio.h>
int main(){
  int n, res;
  while(scanf("%d", &n)!=EOF && n>0 && n<30){
    res = 1;
    while(--n){
      res = 2*res + 2;
    }
    printf("%d\n", res);
  }
  return 0;
}
