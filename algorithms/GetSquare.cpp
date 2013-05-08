/* *
 * judge if n^1/2 is integer
 * */
#include<stdio.h>

//可能溢出，有问题
int getSquare(int n){
  if(n<0)
    return -1;
  int low=0, high=n;
  while(low<high){
    int mid = low + (high-low+1)/2; 
    int res = mid*mid;
    if(res == n)
      return mid;
    else if(res<0 || res>n) //考虑溢出
      high = mid-1;
    else
      low = mid;
  }
  return low;
}


int getSquare2(int n){
  if(n<2)
    return n;
  int low, high, res;
  for(high=2;; high = high<<2){
    res = high*high;
    if(res==n)
      return high;
    else if(res>n)
      break;
  }
  low = high>>2;
  while(low<high){
    int mid = (low+high+1)/2; 
    res = mid*mid;
    if(res==n)
      return mid;
    else if(res>n)
      high = mid-1;
    else
      low = mid;
  }
  return low;
}
int main(){
  int n;
  while(scanf("%d", &n)!=EOF){
    printf("%d\t", n);
    //nprintf("%d\t", getSquare(n)); 
    printf("%d\n", getSquare2(n)); 
  }
}
