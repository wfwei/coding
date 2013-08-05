#include<stdio.h>

bool found = false;

void swap(int *a, int *b){
	if(a==b)
		return;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void canGetVal(int *A, int s, int e, double val){
	int i, j, k, vs1, vs, vs1k, vi, vj;
	if(s<e){
    for(i=s; i<e && !found; i++){
      for(j=i+1; j<=e && !found; j++){
        //save state
        vs=A[s], vs1=A[s+1];
        vi=A[i], vj=A[j];
        
        //do change
        swap(A+s, A+i);
        swap(A+s+1, A+j);
        for(k=0; k<4 && !found; k++){
          vs1k = A[s+1];
          switch(k){
            case 0: A[s+1] = A[s+1]+A[s]; break;
            case 1: A[s+1] = A[s+1]-A[s]; break;
            case 2: A[s+1] = A[s+1]*A[s]; break;
            case 3: A[s+1] = 1.0*A[s+1]/A[s]; break;
          }   
          canGetVal(A, s+1, e, val);
          A[s+1]=vs1k;
        }

        //recover state
        A[s]=vs, A[s+1]=vs1;
        A[i]=vi, A[j]=vj;

      }
    }
	}else{
    if(!(A[s]> val||A[s]<val)){
			found = true;
    }
	}
}

int main(){
	//int A[]={1, 10, 1, 1}; 
	//int A[]={1, 1, 1, 11}; 
	int A[]={3, 3, 8, 8}; 
	//int A[]={6, 7, 2, 8}; 
	//int A[]={2, 4, 6, 12}; 
	//int A[]={6, 6, 6, 6}; 
  found = 0;
  canGetVal(A, 0, 3, 24);
  if(found)
    printf("Found!");
  else
    printf("Not Found!");
}
