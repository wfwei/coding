#include<stdio.h>
#include<math.h>

#define THRESHOLD 0.00001

bool found = false;

void swap(double *a, double *b){
	double tmp = *a;
	*a = *b;
	*b = tmp;
}

void canGetVal(double *A, int s, int e, double val){
	int i, j, k; double vs1, vs, vs1k, vi, vj;
	if(s<e){
		for(i=s; i<e && !found; i++){
			for(j=i+1; j<=e && !found; j++){
				//save state
				vs=A[s], vs1=A[s+1];
				vi=A[i], vj=A[j];

				//do change
				swap(A+s, A+i);
				swap(A+s+1, A+j);
				for(k=0; k<8 && !found; k++){
					vs1k = A[s+1];
					switch(k){
					case 0: A[s+1] = A[s+1]+A[s]; break;
					case 1: A[s+1] = A[s+1]-A[s]; break;
					case 2: A[s+1] = A[s+1]*A[s]; break;
					case 3: A[s+1] = A[s+1]/A[s]; break;
					case 4: A[s+1] = A[s]+A[s+1]; break;
					case 5: A[s+1] = A[s]-A[s+1]; break;
					case 6: A[s+1] = A[s]*A[s+1]; break;
					case 7: A[s+1] = A[s]/A[s+1]; break;
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
		if(A[s]==val){
			//if(!(A[s]> val||A[s]<val)){
			//if(abs(A[s]-val)<THRESHOLD){
			found = true;
		}
	}
}

int main(){
	double A[][4] = {{7, 8, 8, 10}, {1, 3, 4, 6}, {1, 8, 12, 12}, {1, 1, 1, 11}, {6, 7, 2, 8}, {2, 4, 6, 12}, {6, 6, 6, 6}};
	int i, j;
	for(i=0; i<sizeof(A)/sizeof(double)/4; i++){
		found = false;
		canGetVal(A[i], 0, 3, 24);
		for(j=0; j<4; j++){
			printf("%.0lf  ", A[i][j]);
		}
		printf("\t%d\n", found);
	}
	getchar();
}