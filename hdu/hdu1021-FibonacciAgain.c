#include<stdio.h>
int main(){
    long n;
    while(scanf("%ld", &n) != EOF){
        n %= 8;
        if (n==2 || n==6){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
}
