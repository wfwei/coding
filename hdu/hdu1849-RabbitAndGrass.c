/*
 * =====================================================================================
 *
 *       Filename:  hdu1849-RabbitAndGrass.c
 *
 *    Description:  Nim游戏问题，使用神奇的异或运算性质
 *
 *        Version:  1.0
 *        Created:  2013年03月20日 20时12分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  FengweiWang (@WeBless), cf.wfwei@gmail.com
 *   Organization:  workplex
 *
 * =====================================================================================
 */
#include<stdio.h>

int main(){
  int m, k, res;
  while(scanf("%d", &m), res=0, m>0){
    while(m--){
      scanf("%d", &k);
      res ^= k;
    }
    if(res)
      printf("Rabbit Win!\n");
    else
      printf("Grass Win!\n");
  }
  return 0;
}
