#include<stdio.h>
#include<string.h>

#define MAX 10001

int a[MAX];

int main(){
  int T, n, res, i, j;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &n);
    for(i=0; i<n; i++)
      scanf("%d", &a[i]);
    if(n==0)
      res = 0;
    else 
      res = MAX; 
    for(i=0; i<n; i++){
      if(a[i]==0)
        continue;
      int maxv=a[i], ava=a[i];
      for(j=i+1; j<n; j++){
        if(a[j]>maxv)
          maxv = a[j];
        
        if(a[j]>a[j-1])
        else{
          if(maxv-a[j]>=a[i])
            break;
        }
      }

      if(j-i<res)
        res = j-i;
      while(--j>=i)
        a[j] -= a[i];
    }
    printf("%d\n", res);
  }
  return 0;
}
