/*
 * =====================================================================================
 *
 *       Filename:  perm.cpp
 *
 *    Description:  full permulation
 *
 *        Version:  1.0
 *        Created:  2013年03月30日 15时02分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  FengweiWang (@WeBless), cf.wfwei@gmail.com
 *   Organization:  workplex
 *
 * =====================================================================================
 */

#include<stdio.h>
int count=0;

void swap(int *a, int *b){
  int m;
  m = *a;
  *a = *b;
  *b = m;
}

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

int main(){
  int list[] = {1, 2, 3, 4, 5};
  perm(list, 0, 4);
  return 0;
}
