#include<stdio.h>

int main(){
  int n, m, i;
  int ans[40];
  ans[0]=0; ans[1]=1; ans[2]=2;
  for(i=3; i<40; i++){
    ans[i] = ans[i-1] + ans[i-2];
  }
  scanf("%d", &n);
  while(n--){
    scanf("%d", &m);
    printf("%d\n", ans[m-1]);
  }
  return 0;
}
