#include<stdio.h>
#define bitVal(n, i) (((n) & (1 << (i)))>0?1:0)

void findTwoSingleNum(int *A, int len, int fiterBit, int filterVal, int AorB){
    int i, j, Aval=0, Bval=0;
    for(j=0; j<sizeof(int); j++){
        if(bitVal(AorB, j))
            break;
    }
    for(i=0; i<len; i++){
        if(bitVal(A[i], fiterBit) == filterVal){
            if(bitVal(A[i], j))
                Aval ^= A[i];
            else
                Bval ^= A[i];
        }
    }
    printf("%d\t%d\n", Aval, Bval);
}
void findThreeSingleNum(int *A, int len){
    int i, j, XorA=0, XorB=0, XorACount=0, XorBCount=0;
    for(i=0; i<sizeof(int); i++){
        for(j=0; j<len; j++){
            if(bitVal(A[j], i)){
                XorA ^= A[j];
                XorACount ++;
            }else{
                XorB ^= A[j];
                XorBCount ++;
            }
        }
        if(XorACount & 0x1){
            if(XorB==0)
                continue;
            printf("%d\t", XorA);
            findTwoSingleNum(A, len, i,0, XorB);
            break;
        } else {
            if(XorA == 0)
                continue;
            printf("%d\t", XorB);
            findTwoSingleNum(A, len, i, 1, XorA);
            break;
        }
    }
}

//int main(){  
//    int arr[] = {  
//        /*1, 3, -9, 2, 1, 2, -10*/  
//        /*44, 52, 56, 1, 1, 3, 3  */
//        1, 2, 3, 4, 3
//    };  
//    findThreeSingleNum(arr, sizeof(arr) / sizeof(arr[0]));  
//    getchar();
//}  