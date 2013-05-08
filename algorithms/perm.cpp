#include<stdio.h>
#include<string.h>

int count=0;

void swap(int *a, int *b){
  int m;
  m = *a;
  *a = *b;
  *b = m;
}
//全排列
void perm(int list[], int s, int e){
  int i;
  if(s>=e){
    printf("%05d: ", ++count);
    for(i=0; i<=e; i++)
      printf("%d", list[i]);
    printf("\n");
  }else{
    for(i=s; i<=e; i++){
      swap(&list[i], &list[s]);
      perm(list, s+1, e);
      swap(&list[i], &list[s]);
    }
  }
}

void swap(char *a, char *b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

void permutate(char *str, int s, int e){
  int i;
  if(s>=e)
    printf("%s\n", str);
  else{
    for(i=s; i<=e; i++){
      swap(str+i, str+s);
      permutate(str, i+1, e);
      swap(str+i, str+s);
    }
  }
}
void Permutation(char *str){
  if(str==NULL)
    return ;
  int len = strlen(str);
  permutate(str, 0, len-1);
}

int main(){
  int list[] = {1, 2, 3, 4, 5};
  perm(list, 0, 2);
  return 0;
}
