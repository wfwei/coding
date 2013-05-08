#include<stdio.h>
#include<string.h>
#define MAXN 101

int main(){
  int C, n, m, i, p, h, c;
  int dp[MAXN];
  scanf("%d", &C);
  while(C--){
    memset(dp, 0, sizeof(dp));
    scanf("%d %d", &n, &m);
    while(m--){
      scanf("%d %d %d", &p, &h, &c);
      while(c--){
        for(i=n; i>=p; i--){
          if(dp[i-p]+h>dp[i])
            dp[i] = dp[i-p]+h;
        }
      }
    }
    printf("%d\n", dp[n]);
  }
  return 0;
}
