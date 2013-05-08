/*
 * =====================================================================================
 *
 *       Filename:  hdu2566-countCoins.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年03月06日 13时40分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  FengweiWang (@WeBless), cf.wfwei@gmail.com
 *   Organization:  workplex
 *
 * =====================================================================================
 */
#include<stdio.h>

#define MAX 1000

int c1[MAX], c2[MAX];
int coin[] = {1, 2, 5};

int main(){
  int i, j, k, t, m, n;
  if(~scanf("%d", &t)){
     while(t--){
       scanf("%d %d", &n, &m);
       for(i=0; i<=m; i++){
        c1[i] = 1;
        c2[i] = 0;
       }


       for(i=1; i<3; i++){
        for(j=0; j<=m; j++){
          for(k=0; k+j<=m; k+=coin[i]){
            
          }
           
        }
       
       }
     }
  }
}
