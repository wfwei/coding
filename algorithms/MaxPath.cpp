#include<stdio.h>

int count = 0;

void func(int sx, int sy, int ex, int ey){
  if(sx<ex)
    func(sx+1, sy, ex, ey);
  if(sy<ey)
    func(sx, sy+1, ex, ey);
  if(sx==ex && sy==ey)
    count ++;
}

int main(){
  func(1, 1, 3, 3);
  printf("%d", count);
}
