#include<stdio.h>

int calcComb(int n, int m){
  int i, res;
  for(i=1, res=1; i<=m; i++){
    res = res*(n-i+1)/i;
  }
  return res;
}

int calcComb2(int n, int m){
  if(n==m || m==0)
    return 1;
  return calcComb2(n-1, m) + calcComb2(n-1, m-1);
}

int calcComb3(int n, int m){
  int i, j, r[n+1][m+1];
  r[1][0] = r[1][1] = 1;
  for(i=2; i<=n; i++){
    for(j=0; j<=m && j<=i; j++){
      if(j==i || j==0)
        r[i][j] = 1;
      else
        r[i][j] = r[i-1][j] + r[i-1][j-1];
    }
  }
  return r[n][m];
}

int main(){
  int n, m;
  while(scanf("%d %d", &n, &m)!=EOF){
    printf("C(%d,%d)=%d\n", n, m, calcComb(n, m));
    printf("C(%d,%d)=%d\n", n, m, calcComb2(n, m));
    printf("C(%d,%d)=%d\n", n, m, calcComb3(n, m));
  }
  return 0;
}
