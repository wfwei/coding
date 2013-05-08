#include<stdio.h>
#include<string.h>
#define MAX 100

char a[MAX], b[MAX], d[MAX][MAX];

int min3(int a, int b, int c){
  int t = a>b?b:a;
  return t>c?c:t;
}

int editLen(){
  int la=strlen(a), lb=strlen(b);
  int i, j;
  for(i=0; i<=la; i++)
    d[i][0] = i;
  for(j=0; j<=lb; j++)
    d[0][j] = j;
  for(i=1; i<=la; i++){
    for(j=1; j<=lb; j++){
      d[i][j] = min3(d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1] + (a[i-1]==b[j-1]?0:1));
      printf("%d ", d[i][j]);
    }
    printf("\n");
  }

  return d[la][lb];
}

int main(){
  while(scanf("%s %s", a, b)!=EOF){
    printf("%d\n", editLen());
  }
  return 0;
}
