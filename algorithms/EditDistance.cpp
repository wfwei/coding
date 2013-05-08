/*
 * Edit Distance of two string
 */
#include<stdio.h>
#include<string.h>

#define MAX 1000

char A[MAX+1];
char B[MAX+1];
int dp[MAX+1][MAX+1];

int min3(int a, int b, int c){
  int min = a;
  if(min>b)
    min = b;
  if(min>c)
    min = c;
  return min;
}

int dist(){
  int lenA = strlen(A), lenB = strlen(B);
  int i, j;
  for(i=1; i<=lenA; i++)
    dp[0][i] = i;
  for(j=1; j<=lenB; j++)
    dp[j][0] = j;
  
  for(j=0; j<lenB; j++)
    for(i=0; i<lenA; i++){
      dp[j+1][i+1] = min3(dp[j][i+1]+1, dp[j+1][i]+1, dp[j][i]+(A[i]==B[j]?0:1));
    }  
  return dp[lenB][lenA];
}

int main(){
  while(scanf("%s %s", A, B)!=EOF)
    printf("Distance:%d\n", dist());
}
