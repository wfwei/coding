#include<stdio.h>
//这个思路太丑陋了
bool found = false;

void swap(int *a, int *b){
	if(a==b)
		return;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void getVal2(int A[], int s, int e, double val){
	double val1, val2, val3;
	if(found)
		return;
	int i, j, k;
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			for(k=0; k<4; k++){
				if(k!=i && k!=j){
					switch(i){
					case 0: val1 = A[0]+A[1];break;
					case 1: val1 =A[0]-A[1];break;
					case 2: val1 = A[0]*A[1];break;
					case 3: val1 = 1.0*A[0]/A[1];break;
					}

					switch(j){
					case 0: val2 = A[2]+A[3];break;
					case 1: val2 =A[2]-A[3];break;
					case 2: val2 = A[2]*A[3];break;
					case 3: val2 = 1.0*A[2]/A[3];break;
					}

					switch(k){
					case 0: val3 = val1+val2;break;
					case 1: val3 =val1-val2;break;
					case 2: val3 = val1*val2;break;
					case 3: val3 = 1.0*val1/val2;break;
					}
					if(val3==val)
						found = 1;
				}
			}
		}
	}
}

void getVal(int *A, int s, int e, double val){
	int i; double newval;
	if(found)
		return;
	if(s>=e){
		if(!(A[e]>val || A[e]<val))
			found = true;
	}else{
		for(i=0; i<4; i++){
			switch(i){
			case 0: newval = val-A[s];break;
			case 1: newval = val+A[s];break;
			case 2: newval = val*A[s];break;
			case 3: newval = 1.0*val/A[s];break;
			}
			getVal(A, s+1, e, newval);
		}
	}
}

void canGetVal(int *A, int s, int e, double val){
	int i;
	if(found)
		return;
	if(s<e){
		for(i=s; i<=e; i++){
			swap(A+i, A+s);
			canGetVal(A, s+1, e, val);
			swap(A+i, A+s);
		}
	}else{
		getVal(A, 0, e, val);
		getVal2(A, 0, e, val);
	}
}

int can24(int *A){
	found = false;
	canGetVal(A, 0, 3, 24.0);
	return found;
}

int main(){
	int A[]={1, 1, 1, 10}; 
	//int A[]={1, 1, 1, 11}; 
	//int A[]={6, 7, 2, 8}; 
	//int A[]={2, 4, 6, 12}; 
	//int A[]={6, 6, 6, 6}; 
	printf("%d\n", can24(A));
	getchar();
}
