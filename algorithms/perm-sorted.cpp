#include<stdio.h>
int count=0;

void prt(int list[], int fr, int to){
  for(;fr<=to;){
    printf("%d ", list[fr++]);
  }
  printf("\n");
}

void moveClockwise(int list[], int fr, int to){
  int i, tmp = list[to];
  for(i=to-1; i>=fr; i--)
    list[i+1] = list[i];
  list[fr] = tmp;
}

void moveUntiClockwise(int list[], int fr, int to){
  int i, tmp = list[fr];
  for(i=fr+1; i<=to; i++)
    list[i-1] = list[i];
  list[to] = tmp;
}

void perm(int list[], int s, int e){
  int i;
  if(s>=e){
    printf("%05d: ", ++count);
    prt(list, 0, e);
  }else{
    for(i=s; i<=e; i++){
      moveClockwise(list, s, i);
      perm(list, s+1, e);
      moveUntiClockwise(list, s, i);
    }
  }
}

int main(){
  int list[] = {0, 1, 2, 3, 4, 5};
  perm(list, 0, 5);
  return 0;
}
