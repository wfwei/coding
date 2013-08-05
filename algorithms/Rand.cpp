#include<stdio.h>
#include<stdlib.h>

// return random num:0-6
int Rand7(){
    return rand()%7;
}

int Rand10(){
    int rand71, rand72, rand10;
    do{
        rand71 = Rand7();
        rand72 = Rand7();
        rand10 = rand71*7 + rand72;
    }while(rand10>=40);
    return rand10/4 + 1;
}
//int main(){
//    int n=100;
//    while(n--){
//        printf("%d\n", Rand10());
//    }
//    getchar();
//}