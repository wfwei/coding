#include<stdio.h>
#include<string.h>
#include<algorithm>

#define N 11
#define NAME 21

using namespace std;

char heros[N][NAME]; 
int constrain[N][N];
int n, id1[N], id2[N];

int getIdx(char * hero){
  int i=0;
  for(; i<n; i++){
    if(strcmp(heros[i], hero)==0)
      return i;
  }
  return -1;
}

int cmp(const void * p, const void * q){
  return strcmp((char *)p, (char *)q);
}

int win(){
  int i=0, j=0;
  while(i<n&&j<n){
    if(constrain[id2[i]][id1[j]])
      j++;
    else
      i++;
  }
  if(i==n)
    return 1;
  else
    return 0;
}

void check(){
  int i=0, fail=0, over=0;
  for(;i<n; i++)
    id1[i]=id2[i]=i;
  do{
    fail = 0;
    do{
       if(!win())
         fail = 1;
    }while(!fail && next_permutation(id2, id2+n));
    if(!fail){
      over = 1;
      printf("Yes\n");
      for(i=0; i<n-1; i++)
        printf("%s ", heros[id1[i]]);
      printf("%s\n", heros[id1[i]]);
    }
  }while(!over && next_permutation(id1, id1+n));
}

int main(){
  int T, i, k;
  char hero[N];
  scanf("%d", &T);
  while(T--){
    scanf("%d", &n);
    for(i=0; i<n; i++){
      scanf("%s", heros[i]);
    }
    qsort(heros, sizeof(heros[0]), N, cmp);
    memset(constrain, 0, sizeof(constrain));
    for(i=0; i<n; i++){
      scanf("%d", &k);
      while(k--){
        scanf("%s", hero);
        constrain[i][getIdx(hero)] = 1;
      }
    }
    check();
  }
}
