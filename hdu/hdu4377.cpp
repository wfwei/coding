#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<cmath>  
#include<queue>  
#include<map>  
#include<vector>  
  
using namespace std;  
  
const int inf = 0x7fffffff;  
const int inf64 = (int)inf;  
  
int main(){  
    int t,i,j,nn,n,kk,k,f;  
    scanf("%d",&t);  
    while(t--){  
        scanf("%d",&n);  
        if(n==2){  
            puts("1 2");  
            continue;  
        }  
        nn=sqrt((double)(n-1))+1;  
        k=(n-1)/nn;  
        f=0;  
        for(i=1;i<=n;i++){  
            if(k+i>=nn) break;  
            if(f) printf(" %d",i);  
            else{  
                printf("%d",i);   
                f=1;  
            }  
        }  
        if(i<=n){  
            kk=(n-i+1)%nn;  
            for(j=i+kk-1;j<=n;j+=nn){  
                for(k=j;k>=i;k--){  
                    if(f) printf(" %d",k);  
                    else{  
                        printf("%d",k);   
                        f=1;  
                    }  
                }  
                i=j+1;  
            }  
        }  
        puts("");  
    }  
    return 0;  
}  
