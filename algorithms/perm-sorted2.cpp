/**
 * sorted permutation
 */
#include<stdio.h>
#include<string.h>

void moveClockwise(char *str, int s, int e){
  char tmp = str[e];
  while(e>s){
    str[e] = str[e-1];
    e --;
  }
  str[s] = tmp;
}

void moveAntiClockwise(char *str, int s, int e){
  char tmp = str[s];
  while(e>s){
    str[s] = str[s+1];
    s++;
  }
  str[e] = tmp;
}

void permutate(char *str, int s, int e){
  if(s>=e)
    printf("%s\n", str);
  else{
    int i;
    for(i=s; i<=e; i++){
      moveClockwise(str, s, i);
      permutate(str, s+1, e);
      moveAntiClockwise(str, s, i);
    }
  }
}

void permutation(char *str){
  int len=strlen(str);
  permutate(str, 0, len-1);
}

int main(){
  char str[] = {'a', 'b', 'c', '\0'};
  permutation(str);
}
