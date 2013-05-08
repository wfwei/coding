//All combinations, 输入ab，排列组合有a、b、ab、ba。
#include<stdio.h>
int count=0;

void swap(int *a, int *b){
  int m;
  m = *a;
  *a = *b;
  *b = m;
}

void comb(int list[], int s, int e){
  int i;
  if(s>0){
    printf("%010d:\t", ++count);
    for(i=0; i<=s-1; i++){
      printf("%d ", list[i]);
    }
    printf("\n");
  }
  for(i=s; i<=e; i++){
    swap(&list[i], &list[s]);
    comb(list, s+1, e);
    swap(&list[i], &list[s]);
  }
}

int main(){
  int list[] = {1, 2, 3, 4, 5};
  comb(list, 0, 2);
  return 0;
}
